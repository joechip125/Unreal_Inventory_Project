// Fill out your copyright notice in the Description page of Project Settings.


#include "AreaRenderingComponent.h"

#include "AreaRenderSceneProxy.h"

UAreaRenderingComponent::UAreaRenderingComponent(const FObjectInitializer& ObjectInitializer)
: UPrimitiveComponent(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;
	SetCastShadow(false);

#if WITH_EDITORONLY_DATA
	SetIsVisualizationComponent(true);
#endif

	SetHiddenInGame(false);
	bVisibleInReflectionCaptures = false;
	bVisibleInRayTracing = false;
	bVisibleInRealTimeSkyCaptures = false;
	AlwaysLoadOnClient = false;
	bIsEditorOnly = true;
}

FPrimitiveSceneProxy*  UAreaRenderingComponent::CreateSceneProxy()
{
	auto Proxy = new FAreaRenderSceneProxy(this);

	const FTransform& XForm = GetComponentTransform();

	//XForm.TransformPosition(L.Start),
	
	for(auto& L : Lines)
	{
		Proxy->Lines.Add(FDebugRenderSceneProxy::FDebugLine(L.Start,L.End, L.Color, L.LineThickness));
	}

	for (auto& Box : Cubes)
	{
		FVector HalfSize = Box.Size * 0.5f;
		FBox DBox(-HalfSize, HalfSize);
		// Apply local rotation first then parent transform
		FTransform CombinedXForm = FTransform(Box.Rotation, Box.Position);// * XForm;
		Proxy->Boxes.Add(FDebugRenderSceneProxy::FDebugBox(
			DBox, Box.Color, CombinedXForm));
	}
	
	return Proxy;
}

FBoxSphereBounds UAreaRenderingComponent::CalcBounds(const FTransform& LocalToWorld) const
{
	FBoxSphereBounds B = Super::CalcBounds(LocalToWorld);

	for (auto& L : Lines)
	{
		// Re-centre the origin of the line to make box extents 
		FVector Extents = L.Start.GetAbs().ComponentMax(L.End.GetAbs());
		B = B + FBoxSphereBounds(FVector::ZeroVector, Extents, Extents.GetMax());
	}

	for (auto& Box : Cubes)
	{
		FVector HalfSize = Box.Size * 0.5f;
		FBox DBox(-HalfSize, HalfSize);
		// Apply local rotation only, world is done later
		FTransform BoxXForm = FTransform(Box.Rotation, Box.Position);
		DBox = DBox.TransformBy(BoxXForm);
		B = B + FBoxSphereBounds(DBox);
	}

	return B.TransformBy(LocalToWorld);
}
