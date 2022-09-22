// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EnumContainer.generated.h"

UENUM(BlueprintType, meta=(Bitflags))
enum class EAreaSearchCriteria : uint8
{
	None = 0 UMETA(Hidden),
	Resources = 1 << 1,
	Player = 1 << 2,
	Path = 1 << 3,
	OtherEnemy = 1 << 4
};

UENUM(BlueprintType)
enum ESearchPointState
{
	Free,
	Taken,
	Clear
};
