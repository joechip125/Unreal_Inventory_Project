// Fill out your copyright notice in the Description page of Project Settings.


#include "Scanner.h"

#include "../../../../Developer/RiderLink/Source/RD/thirdparty/spdlog/include/spdlog/fmt/bundled/format.h"


// Sets default values
AScanner::AScanner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RenderComponent = CreateDefaultSubobject<UAreaRenderingComponent>(TEXT("RenderComp"));
	RenderComponent->SetupAttachment(GetRootComponent());
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

void AScanner::LineScan(FVector Start, FVector End, int numberScans)
{
	float increment = FVector::Distance(Start, End) / numberScans;
	FVector dir = End - Start;
	dir.Normalize();
	FVector current = Start;
	FVector traceDir = FVector(1,0,0);
	for(int i = 0; i <  numberScans; i++)
	{
		auto hit = DoATrace(current, current + traceDir * 600);
		auto line = FEditorVisLine(current, current + traceDir * 600, hit.bBlockingHit ? FColor::Green : FColor::Red);
		RenderComponent->Lines.Add(line);
		current += FVector(dir.X * increment, dir.Y * increment, dir.Z * increment);
	}
}

void AScanner::AddCube(FVector Pos, FVector Size)
{
	auto cube = FEditorVisCube(Pos, Size, FColor::Emerald);
	RenderComponent->Cubes.Add(cube);
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

