// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DebugRenderSceneProxy.h"


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

	
	virtual void GetDynamicMeshElements(const TArray<const FSceneView*>& Views, const FSceneViewFamily& ViewFamily,
										uint32 VisibilityMap, FMeshElementCollector& Collector) const override;

	 virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View) const override;

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