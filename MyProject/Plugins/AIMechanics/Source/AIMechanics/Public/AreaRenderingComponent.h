// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Debug/DebugDrawComponent.h"
#include "UObject/Object.h"
#include "AreaRenderingComponent.generated.h"


class FAreaRenderSceneProxy : public FPrimitiveSceneProxy
{
public:
	FAreaRenderSceneProxy(const UPrimitiveComponent* InComponent, const FName& ResourceName)
		: FPrimitiveSceneProxy(InComponent, ResourceName)
	{
	}

	explicit FAreaRenderSceneProxy(FPrimitiveSceneProxy const& PrimitiveSceneProxy)
		: FPrimitiveSceneProxy(PrimitiveSceneProxy)
	{
	}

	struct FDebugBox
	{
		FDebugBox(const FBox& InBox, const FColor& InColor)
			: Box(InBox), Color(InColor)
		{
		}

		FDebugBox(const FBox& InBox, const FColor& InColor, const FTransform& InTransform)
			: Box(InBox), Color(InColor), Transform(InTransform)
		{
			
		}

		FBox Box;
		FColor Color;
		FTransform Transform;
	};
	
	struct FText3d
	{
		FText3d() {}
		FText3d(const FString& InString, const FVector& InLocation, const FLinearColor& InColor) :
		Text(InString),
		Location(InLocation),
		Color(InColor.ToFColor(true)) {}

		FString Text;
		FVector Location;
		FColor Color;
	};
	
	

	TArray<FDebugBox> Boxes;
	TArray<FText3d> Texts;
};

UCLASS()
class AIMECHANICS_API UAreaRenderingComponent : public UDebugDrawComponent
{
	GENERATED_BODY()

	TArray<FAreaRenderSceneProxy::FDebugBox> Boxes;
};
