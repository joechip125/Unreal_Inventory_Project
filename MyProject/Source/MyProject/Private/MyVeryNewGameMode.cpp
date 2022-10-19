// Fill out your copyright notice in the Description page of Project Settings.


#include "MyVeryNewGameMode.h"

AMyVeryNewGameMode::AMyVeryNewGameMode():
Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}
