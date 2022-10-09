﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Scanner.h"

#include "../../../../Developer/RiderLink/Source/RD/thirdparty/spdlog/include/spdlog/fmt/bundled/format.h"
#include "Components/InstancedStaticMeshComponent.h"


// Sets default values
AScanner::AScanner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RenderComponent = CreateDefaultSubobject<UAreaRenderingComponent>(TEXT("RenderComp"));
	RenderComponent->SetupAttachment(GetRootComponent());

	CubeInstance = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("CubeInstance"));
	CubeInstance->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AScanner::BeginPlay()
{
	Super::BeginPlay();
	
}

void AScanner::CircleScan(FVector Center, float Radius, int numberScans)
{
	RenderComponent->Lines.Empty(numberScans);
	float degree = 0;
	numberScans = FMath::Clamp(numberScans, 1, 360);
	const int increment = 360 / numberScans;
	
	for(int i = 0; i <  numberScans; i++)
	{
		float theSin = FMath::Sin(FMath::DegreesToRadians(degree)) * Radius;
		float theCos = FMath::Cos(FMath::DegreesToRadians(degree)) * Radius;
		auto pos = Center + FVector(theCos, theSin,0);
		auto hit = DoATrace(pos, Center);

		if(hit.bBlockingHit)
		{
			pos = hit.Location;
			auto cube = FEditorVisCube(pos, FVector(10,10,10), FColor::Emerald);
			RenderComponent->Cubes.Add(cube);
		}
		
		auto line = FEditorVisLine(pos, Center, hit.bBlockingHit ? FColor::Green : FColor::Red);
		RenderComponent->Lines.Add(line);

		degree += increment;
	}
}

void AScanner::ClearAll(int Slack)
{
	RenderComponent->Lines.Empty(Slack);
	RenderComponent->Cubes.Empty(Slack);
}

void AScanner::LineScan(FVector Start, FVector End, FVector traceDir, int numberScans)
{
	RenderComponent->Lines.Empty(numberScans);
	//RenderComponent->Cubes.Empty(numberScans);
	float increment = FVector::Distance(Start, End) / numberScans;
	FVector dir = End - Start;
	dir.Normalize();
	FVector current = Start;
	FVector cubeSize = FVector(increment);
	for(int i = 0; i <  numberScans; i++)
	{
		FVector TheEnd = current + traceDir * 600;
		auto hit = DoATrace(current, TheEnd);

		if(hit.bBlockingHit)
		{
			TheEnd = hit.Location;
			auto aColor = hit.GetComponent()->GetMaterial(0)->GetMaterial()->BaseColor.Constant;
			//GEngine->AddOnScreenDebugMessage(0, 3, FColor::Cyan, aColor.ToString());
			auto cube = FEditorVisCube(TheEnd, cubeSize, FColor::Emerald);
			if(CanAddCube(TheEnd, cubeSize.X))
			{
				RenderComponent->Cubes.Add(cube);
			}
		}
		
		auto line = FEditorVisLine(current, TheEnd, hit.bBlockingHit ? FColor::Green : FColor::Red);
		RenderComponent->Lines.Add(line);
		current += FVector(dir.X * increment, dir.Y * increment, dir.Z * increment);
	}
}

void AScanner::AddCube(FVector Pos, FVector Size)
{
	auto cube = FEditorVisCube(Pos, Size, FColor::Emerald);
	RenderComponent->Cubes.Add(cube);
}

bool AScanner::CanAddCube(FVector SuggestedPos, float tolerance) const
{
	for(auto Cube : RenderComponent->Cubes)
	{
		if(FVector::Distance(Cube.Position, SuggestedPos) < tolerance)
		{
			return false;
		}
	}
	return true;
}

FHitResult AScanner::DoATrace(FVector Start, FVector End)
{
	auto HitResult = FHitResult();
	auto Query = FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldStatic);
	GetWorld()->LineTraceSingleByObjectType(HitResult, Start, End, Query);
	return HitResult;
}

// Called every frame
void AScanner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

