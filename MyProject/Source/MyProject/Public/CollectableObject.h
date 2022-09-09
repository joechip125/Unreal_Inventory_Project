// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FloatMoveComp.h"
#include "GameFramework/Actor.h"
#include "CollectableObject.generated.h"

UCLASS()
class MYPROJECT_API ACollectableObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectableObject();

	/**
	* This is a movement component
	*/
	UPROPERTY()
	UFloatMoveComp* moveComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
