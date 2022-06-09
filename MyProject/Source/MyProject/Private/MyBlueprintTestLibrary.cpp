// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintTestLibrary.h"

void UMyBlueprintTestLibrary::Hello()
{
	if(!GEngine) return;
	
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, TEXT("Hello you"));
}
