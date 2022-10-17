// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilityControllerBase.generated.h"

UCLASS()
class MYPROJECT_API AAbilityControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAbilityControllerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void AcknowledgePossession(APawn* P) override;
};
