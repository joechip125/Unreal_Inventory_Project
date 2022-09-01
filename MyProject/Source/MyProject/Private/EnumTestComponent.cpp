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

//bool UEnumTestComponent::IsMatch(int32 Bitmask)
//{
//	return Bitmask & QualityFlags == Bitmask;
//}



// Called when the game starts
void UEnumTestComponent::BeginPlay()
{
	int32 mask = 1 >> 2 | 1 >> 3;
	ECharacterQualities qual = ECharacterQualities::DARK | ECharacterQualities::HANDSOME;
	ECharacterQualities qual2 = ECharacterQualities::DARK | ECharacterQualities::HANDSOME;
	qual2 |= ECharacterQualities::PROGRAMMER;
	qual2 &= ~ECharacterQualities::PROGRAMMER;  
	QualityFlags |= 1 >> 2;

	
	if(mask & QualityFlags)
	//{
	//	
	//}
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEnumTestComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

