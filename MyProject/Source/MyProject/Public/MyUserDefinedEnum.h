// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "MyUserDefinedEnum.generated.h"


//macros
#define TEST_BIT(Bitmask, Bit) (((Bitmask) & (1 << static_cast<uint32>(Bit))) > 0)
#define SET_BIT(Bitmask, Bit) (Bitmask |= 1 << static_cast<uint32>(Bit))
#define CLEAR_BIT(Bitmask, Bit) (Bitmask) &= ~(1 << static_cast<uint32>(Bit)))

UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class ECharacterQualities: uint8
{
	NONE	   = 0 UMETA(Hidden),
	TALL	   = 1 << 0,
	DARK	   = 1 << 1,
	HANDSOME   = 1 << 2,
	PROGRAMMER = 1 << 3,
};
ENUM_CLASS_FLAGS(ECharacterQualities);


