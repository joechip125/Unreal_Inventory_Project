// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StructContainer.generated.h"


USTRUCT()
struct FSearchAreaStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector PointPos;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool PointSeen;
	
};

