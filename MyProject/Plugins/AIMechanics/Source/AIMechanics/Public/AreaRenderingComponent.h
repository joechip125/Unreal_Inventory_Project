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

	struct FDebugCircle
	{
		FDebugCircle(const FVector& InCentre, const FVector& InX, const FVector& InY, float InRadius, int InNumSegments,
					 const FColor& InColor, float InThickness = 0) :
			Centre(InCentre),
			X(InX),
			Y(InY),
			Radius(InRadius),
			NumSegments(InNumSegments),
			Color(InColor),
			Thickness(InThickness)
		{
		}

		FVector Centre;
		FVector X;
		FVector Y;
		float Radius;
		int NumSegments;
		FColor Color;
		float Thickness;
	};
};

UCLASS()
class AIMECHANICS_API UAreaRenderingComponent : public UDebugDrawComponent
{
	GENERATED_BODY()
public:
	UAreaRenderingComponent(const FObjectInitializer& ObjectInitializer);
	
protected:
	virtual FDebugRenderSceneProxy* CreateDebugSceneProxy() override;
private:
	TArray<FAreaRenderSceneProxy::FDebugBox> Boxes;
	TArray<FAreaRenderSceneProxy::FDebugLine> Lines;
};
