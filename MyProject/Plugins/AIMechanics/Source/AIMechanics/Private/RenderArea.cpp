// Fill out your copyright notice in the Description page of Project Settings.


#include "RenderArea.h"


// Sets default values
ARenderArea::ARenderArea()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AreaVolume = CreateDefaultSubobject<AAreaControlVolume>("AreaVolume");
	
}

// Called when the game starts or when spawned
void ARenderArea::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARenderArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

