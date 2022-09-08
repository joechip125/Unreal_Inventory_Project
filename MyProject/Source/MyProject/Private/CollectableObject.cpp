// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectableObject.h"

// Sets default values
ACollectableObject::ACollectableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	moveComp = CreateDefaultSubobject<UFloatMoveComp>(TEXT("moveComp"));

}

// Called when the game starts or when spawned
void ACollectableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

