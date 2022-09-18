// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "ItemPDABAse.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UItemPDABAse : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FGameplayTagContainer Tags;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UStaticMesh* Mesh;
};
