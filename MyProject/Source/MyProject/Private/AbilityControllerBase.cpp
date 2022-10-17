// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityControllerBase.h"

#include "MyProject/TP_ThirdPerson/TP_ThirdPersonCharacter.h"


// Sets default values
AAbilityControllerBase::AAbilityControllerBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAbilityControllerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbilityControllerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAbilityControllerBase::AcknowledgePossession(APawn* P)
{
	Super::AcknowledgePossession(P);

	ATP_ThirdPersonCharacter* CharacterBase = Cast<ATP_ThirdPersonCharacter>(P);
	if (CharacterBase)
	{
		CharacterBase->GetAbilitySystemComponent()->InitAbilityActorInfo(CharacterBase, CharacterBase);
	}
}

