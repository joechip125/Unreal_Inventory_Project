// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../../../../../Program Files/Epic Games/UE_5.0/Engine/Plugins/Runtime/GameplayAbilities/Source/GameplayAbilities/Public/AbilitySystemInterface.h"
#include "GameFramework/Actor.h"
#include "AbilityActorTest.generated.h"

UCLASS()
class MYPROJECT_API AAbilityActorTest : public AActor, public IAbilitySystemInterface
{
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
private:
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAbilityActorTest();

	UPROPERTY()
	UAbilitySystemComponent* AbilityComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
