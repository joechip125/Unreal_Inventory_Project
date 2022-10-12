// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Debug/DebugDrawComponent.h"
#include "AreaRenderingComponent.generated.h"

USTRUCT(BlueprintType)
struct AIMECHANICS_API FEditorVisCube
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Position;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator Rotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Size;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor Color;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LineThickness;

	FEditorVisCube(const FVector& InPos, const FVector& InSize,
						 const FColor& InColour)
		: Position(InPos),
		  Rotation(FRotator::ZeroRotator),
		  Size(InSize),
	      Color(InColour),
		  LineThickness(0)	
	{
	}
	FEditorVisCube(const FVector& InPos, const FVector& InSize,
						 const FColor& InColour, const float& LineThickness)
		: Position(InPos),
		  Rotation(FRotator::ZeroRotator),
		  Size(InSize),
		  Color(InColour),
		  LineThickness(LineThickness)	
	{
	}

	FEditorVisCube(const FVector& InPos, const FVector& InSize,
						 const FColor& InColour, const float& LineThickness, FRotator rotation)
		: Position(InPos),
		  Rotation(rotation),
		  Size(InSize),
		  Color(InColour),
		  LineThickness(LineThickness)	
	{
	}

	FEditorVisCube():
		Position(FVector::ZeroVector),
		Rotation(FRotator::ZeroRotator),
		Size(FVector(100, 0, 0)),
		Color(FColor::White),
	    LineThickness(10)	
	{
	}
};


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
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEditorVisLine> Lines;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEditorVisCube> Cubes;
};
