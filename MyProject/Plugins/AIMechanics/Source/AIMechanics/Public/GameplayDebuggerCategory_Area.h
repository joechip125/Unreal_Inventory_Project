// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMEPLAY_DEBUGGER
#include "GameplayDebuggerCategory.h"

class AActor;
class APlayerController;
class FGameplayDebuggerCanvasContext;

class AIMECHANICS_API FGameplayDebuggerCategory_Area : public FGameplayDebuggerCategory
{
public:
	FGameplayDebuggerCategory_Area();

	static TSharedRef<FGameplayDebuggerCategory> MakeInstance();
};

#endif