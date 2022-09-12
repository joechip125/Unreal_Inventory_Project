﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

USTRUCT()
struct FItems
{
	GENERATED_BODY()
	
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INVENTORY_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

	UPROPERTY(BlueprintReadWrite)
	TArray<FItems> Items;

	UFUNCTION(BlueprintCallable)
	void AddItem(FItems item);

	UFUNCTION(BlueprintCallable)
	TArray<FItems> GetItems();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
