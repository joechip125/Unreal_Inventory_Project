// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemPDA.h"
#include "UObject/Object.h"
#include "ItemEquip.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UItemEquip : public UItemPDA
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAnimMontage* AttackMontage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAnimMontage* EquipMontage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName AttachSlot;
	
};
