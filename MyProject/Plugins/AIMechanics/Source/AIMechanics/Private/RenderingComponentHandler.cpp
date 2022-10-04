// Fill out your copyright notice in the Description page of Project Settings.


#include "RenderingComponentHandler.h"


// Sets default values
ARenderingComponentHandler::ARenderingComponentHandler()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RenderComponent = CreateDefaultSubobject<UAreaRenderingComponent>("Render Component");
	RenderComponent->SetupAttachment(GetRootComponent());
}

void ARenderingComponentHandler::SetArray(int numX, int numY, float distance, FVector start)
{
	RenderComponent->Lines.Empty();
	start = GetOwner()->GetActorLocation();
	for (int i = 0; i < numX; i++)
	{
		for (int j = 0; j < numY; j++)
		{
			auto Line = FEditorVisLine(start + FVector(0, distance * j, 0), start + FVector(0,distance * j, 500), FColor::Emerald, 5);
			RenderComponent->Lines.Add(Line);
		}
		
		start += FVector(distance, 0, 0);
	}
	
}

// Called when the game starts or when spawned
void ARenderingComponentHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARenderingComponentHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

