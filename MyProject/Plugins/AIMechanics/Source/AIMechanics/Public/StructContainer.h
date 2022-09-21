// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumContainer.h"
#include "UObject/Object.h"
#include "StructContainer.generated.h"


USTRUCT(BlueprintType)
struct FSearchAreaStruct
{
	GENERATED_BODY()

	FSearchAreaStruct()
	{
		PointSeen = false;
		PointState = Free;
	}
	
	FSearchAreaStruct(FVector thePoint, bool pointSeen = false)
	{
		PointPos = thePoint;
		PointSeen = pointSeen;
		PointState = Free;
	}
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector PointPos;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool PointSeen;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ESearchPointState> PointState;
	
};

