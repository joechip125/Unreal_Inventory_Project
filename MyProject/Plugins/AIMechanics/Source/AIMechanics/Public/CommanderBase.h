// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CommanderBase.generated.h"

UCLASS()
class AIMECHANICS_API ACommanderBase : public ACharacter
{
	GENERATED_BODY()

	friend class FAreaComponentVisualizer;

public:
	// Sets default values for this character's properties
	ACommanderBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
