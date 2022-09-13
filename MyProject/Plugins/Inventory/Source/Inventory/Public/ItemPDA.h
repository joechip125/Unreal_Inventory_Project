﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemPDA.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UItemPDA : public UPrimaryDataAsset
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
};
