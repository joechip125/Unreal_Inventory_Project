// Fill out your copyright notice in the Description page of Project Settings.


#include "AreaRenderingComponent.h"

UAreaRenderingComponent::UAreaRenderingComponent(const FObjectInitializer& ObjectInitializer)
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

FDebugRenderSceneProxy* UAreaRenderingComponent::CreateDebugSceneProxy()
{
	auto Proxy = new FAreaRenderSceneProxy(this);

	const FTransform& XForm = GetComponentTransform();
	
	for(auto& L : Lines)
	{
		Proxy->Lines.Add(FDebugRenderSceneProxy::FDebugLine(XForm.TransformPosition(L.Start),
														  XForm.TransformPosition(L.End), FColor::Purple));
	}
	
	return Super::CreateDebugSceneProxy();
}
