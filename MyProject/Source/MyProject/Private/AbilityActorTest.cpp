// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityActorTest.h"

#include "../../../../../../Program Files/Epic Games/UE_5.0/Engine/Plugins/Runtime/GameplayAbilities/Source/GameplayAbilities/Public/AbilitySystemComponent.h"


UAbilitySystemComponent* AAbilityActorTest::GetAbilitySystemComponent() const
{
	return AbilityComponent;
}

// Sets default values
AAbilityActorTest::AAbilityActorTest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("root");
	AbilityComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilityComponent");
	AbilityComponent->SetIsReplicated(true);
}

// Called when the game starts or when spawned
void AAbilityActorTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbilityActorTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

