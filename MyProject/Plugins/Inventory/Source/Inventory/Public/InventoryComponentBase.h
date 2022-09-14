// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemPDA.h"
#include "Components/ActorComponent.h"
#include "InventoryStructs.h"
#include "InventoryComponentBase.generated.h"

#define PRINT_INFO(Text)GEngine->AddOnscreenDebugMessage(-1, 15, FColor::Orange, Text);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMulticastOneParam, FItems, item);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORY_API UInventoryComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponentBase();
	
	UPROPERTY(BlueprintAssignable)
	FMulticastOneParam OnInventoryChanged;

	UPROPERTY(BlueprintReadWrite)
	TArray<FItems> Items;

	UFUNCTION(BlueprintCallable)
	void AddItem(const FItems& item);

	UFUNCTION(BlueprintCallable)
	TArray<FItems>& GetItems();

	UFUNCTION(BlueprintCallable)
	bool RemoveItem(const FItems& item);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
