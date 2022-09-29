// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Debug/DebugDrawComponent.h"
#include "UObject/Object.h"
#include "AreaRenderingComponent.generated.h"


class FAreaRenderSceneProxy final : public FDebugRenderSceneProxy
{
public:
	explicit FAreaRenderSceneProxy(const UPrimitiveComponent* InComponent)
		: FDebugRenderSceneProxy(InComponent)
	{
	}

	explicit FAreaRenderSceneProxy(FDebugRenderSceneProxy const& DebugRenderSceneProxy)
		: FDebugRenderSceneProxy(DebugRenderSceneProxy)
	{
	}
};

UCLASS()
class AIMECHANICS_API UAreaRenderingComponent : public UDebugDrawComponent
{
	GENERATED_BODY()

	TArray<FAreaRenderSceneProxy::FDebugBox> Boxes;
};
