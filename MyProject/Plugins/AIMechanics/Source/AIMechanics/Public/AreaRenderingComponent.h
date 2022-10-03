// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Debug/DebugDrawComponent.h"
#include "AreaRenderingComponent.generated.h"


USTRUCT(BlueprintType)
struct AIMECHANICS_API FEditorVisLine
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Start;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector End;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor Color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LineThickness;

	FEditorVisLine(const FVector& InStart, const FVector& InEnd,
						 const FColor& InColour)
		: Start(InStart),
		  End(InEnd),
		  Color(InColour), LineThickness(0)
	{
	}
	FEditorVisLine(const FVector& InStart, const FVector& InEnd,
						 const FColor& InColour, const float& LineThickness)
		: Start(InStart),
		  End(InEnd),
		  Color(InColour),
		  LineThickness(LineThickness)
	{
	}

	FEditorVisLine():
		Start(FVector::ZeroVector),
		End(FVector(100, 0, 0)),
		Color(FColor::White),
		LineThickness(10)
	{
	}
};


UCLASS(Blueprintable, meta=(DisplayName="Editor Visualisation", BlueprintSpawnableComponent), hidecategories=(Collision,Physics,Object,LOD,Lighting,TextureStreaming))
class AIMECHANICS_API UAreaRenderingComponent : public UPrimitiveComponent
{
	GENERATED_BODY()
public:
	UAreaRenderingComponent(const FObjectInitializer& ObjectInitializer);
	
protected:
	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
public:
	virtual FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;

	virtual bool ShouldRecreateProxyOnUpdateTransform() const override { return true; }
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEditorVisLine> Lines;
};
