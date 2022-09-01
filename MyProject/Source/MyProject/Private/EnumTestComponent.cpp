// Fill out your copyright notice in the Description page of Project Settings.


#include "EnumTestComponent.h"

// Sets default values for this component's properties
UEnumTestComponent::UEnumTestComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

bool UEnumTestComponent::IsMatch(int32 Bitmask)
{
	return Bitmask & QualityFlags == Bitmask;
}


// Called when the game starts
void UEnumTestComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEnumTestComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

