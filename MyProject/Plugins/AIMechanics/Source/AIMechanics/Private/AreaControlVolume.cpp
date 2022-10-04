// Fill out your copyright notice in the Description page of Project Settings.


#include "AreaControlVolume.h"
#include "Components/BrushComponent.h"

AAreaControlVolume::AAreaControlVolume(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static FName CollisionProfileName(TEXT("AreaVolume"));
	GetBrushComponent()->SetCollisionProfileName(CollisionProfileName);

	bColored = true;
	BrushColor.R = 100;
	BrushColor.G = 255;
	BrushColor.B = 100;
	BrushColor.A = 255;
	
}



