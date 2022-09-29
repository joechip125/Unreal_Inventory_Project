// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemEquip.h"
#include "UObject/Object.h"
#include "EquippedObjectComponent.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UEquippedObjectComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UItemEquip* EquippedItem;

	UFUNCTION(BlueprintCallable)
	bool EquipItem(UItemEquip* ItemTo);
};
