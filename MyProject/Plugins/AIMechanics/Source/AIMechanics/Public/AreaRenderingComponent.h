// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AreaRenderSceneProxy.h"
#include "Debug/DebugDrawComponent.h"
#include "UObject/Object.h"
#include "AreaRenderingComponent.generated.h"


UCLASS(Blueprintable)
class AIMECHANICS_API UAreaRenderingComponent : public UDebugDrawComponent
{
	GENERATED_BODY()
public:
	UAreaRenderingComponent(const FObjectInitializer& ObjectInitializer);
	
protected:
	virtual FDebugRenderSceneProxy* CreateDebugSceneProxy() override;
public:
	virtual FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;
public:
	
	TArray<FAreaRenderSceneProxy::FDebugBox> Boxes;
	TArray<FAreaRenderSceneProxy::FDebugLine> Lines;
};
