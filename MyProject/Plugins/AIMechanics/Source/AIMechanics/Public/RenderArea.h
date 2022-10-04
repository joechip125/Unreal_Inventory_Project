﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AreaControlVolume.h"
#include "GameFramework/Actor.h"
#include "RenderArea.generated.h"

UCLASS()
class AIMECHANICS_API ARenderArea : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	AAreaControlVolume* AreaVolume;
	
	// Sets default values for this actor's properties
	ARenderArea();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
