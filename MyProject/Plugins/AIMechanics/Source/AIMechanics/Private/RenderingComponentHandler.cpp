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
	start = GetActorLocation();
	
	for (int i = 0; i < numX; i++)
	{
		for (int j = 0; j < numY; j++)
		{
			auto Line = FEditorVisLine(start + FVector(0, distance * j, 0), start + FVector(0,distance * j, 1000), FColor::Emerald, 5);
			RenderComponent->Lines.Add(Line);
			TraceSomething(start + FVector(0,distance * j, 100), start + FVector(500,distance * j,100));
		}
		
		start += FVector(distance, 0, 0);
	}
	
}

void ARenderingComponentHandler::TraceSomething(FVector start, FVector end)
{
	FHitResult result = FHitResult();
	auto params = FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldStatic);
	GetWorld()->LineTraceSingleByObjectType(result, start, end, params);
	DrawDebugLine(GetWorld(), start,end, result.bBlockingHit ? FColor::Red : FColor::Green, false, 2);
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

