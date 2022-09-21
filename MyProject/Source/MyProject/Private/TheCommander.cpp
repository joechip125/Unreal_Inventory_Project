// Fill out your copyright notice in the Description page of Project Settings.


#include "TheCommander.h"

// Sets default values
ATheCommander::ATheCommander()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATheCommander::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATheCommander::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATheCommander::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

