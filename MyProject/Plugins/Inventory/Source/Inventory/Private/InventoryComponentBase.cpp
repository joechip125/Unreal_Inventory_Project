// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponentBase.h"


// Sets default values for this component's properties
UInventoryComponentBase::UInventoryComponentBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UInventoryComponentBase::AddItem(const FItems& item)
{
	OnInventoryChanged.Broadcast(item);
	Items.Add(item);
}

TArray<FItems>& UInventoryComponentBase::GetItems()
{
	return Items;
}

bool UInventoryComponentBase::RemoveItem(const FItems& item)
{
	return Items.Remove(item) > 0;
	
	for (int i = 0; i < Items.Num(); i++)
	{
		
	}
	
	return false;
}

// Called when the game starts
void UInventoryComponentBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponentBase::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

