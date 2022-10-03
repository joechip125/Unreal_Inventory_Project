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

	SetHiddenInGame(true);
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
	
	for(auto& L : Lines)
	{
		Proxy->Lines.Add(FDebugRenderSceneProxy::FDebugLine(XForm.TransformPosition(L.Start),
														  XForm.TransformPosition(L.End), L.Color, L.LineThickness));
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

	return B.TransformBy(LocalToWorld);
}
