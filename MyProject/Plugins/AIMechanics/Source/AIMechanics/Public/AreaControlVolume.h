// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Volume.h"
#include "AreaControlVolume.generated.h"

UCLASS()
class AIMECHANICS_API AAreaControlVolume : public AVolume
{
	GENERATED_BODY()

public:
	explicit AAreaControlVolume(const FObjectInitializer& ObjectInitializer);
};
