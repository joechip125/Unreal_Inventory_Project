// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayDebuggerCategory_Area.h"

FGameplayDebuggerCategory_Area::FGameplayDebuggerCategory_Area()
{
	
}

TSharedRef<FGameplayDebuggerCategory> FGameplayDebuggerCategory_Area::MakeInstance()
{
	return MakeShareable(new FGameplayDebuggerCategory_Area());
}
