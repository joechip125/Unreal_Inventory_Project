// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AreaVisComponent.generated.h"


USTRUCT(BlueprintType)
struct FEditorVisLine
{
	GENERATED_BODY()

	/// Start location relative to component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Start;
	/// End location relative to component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector End;
	/// The colour of the line render 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor Color;

	FEditorVisLine(const FVector& InStart, const FVector& InEnd,
						 const FColor& InColour)
		: Start(InStart),
		  End(InEnd),
		  Color(InColour)
	{
	}

	FEditorVisLine():
		Start(FVector::ZeroVector),
		End(FVector(100, 0, 0)),
		Color(FColor::White)
	{
	}
};
