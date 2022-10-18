// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "ItemPDA.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORY_API UItemPDA : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	FText Name;
	UPROPERTY(BlueprintReadWrite)
	float Damage;
	UPROPERTY(BlueprintReadWrite)
	UStaticMesh* ObjectMesh;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* DisplayImage;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FGameplayTagContainer Tags;
	
};
