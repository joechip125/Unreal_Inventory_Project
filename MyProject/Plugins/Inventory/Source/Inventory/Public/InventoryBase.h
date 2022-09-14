// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryComponentBase.h"
#include "Components/ActorComponent.h"
#include "InventoryBase.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMulticastOneParam, FItems, item);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORY_API UInventoryBase : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryBase();
	
	UPROPERTY(BlueprintAssignable, Category="Delegates")
	FMulticastOneParam sig;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
