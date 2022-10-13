// Fill out your copyright notice in the Description page of Project Settings.


#include "Scanner.h"

#include "../../../../Developer/RiderLink/Source/RD/thirdparty/spdlog/include/spdlog/fmt/bundled/format.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "GenericPlatform/GenericPlatformApplicationMisc.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Materials/MaterialInstanceDynamic.h"


// Sets default values
AScanner::AScanner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	RootComponent = CreateDefaultSubobject<USceneComponent>("root");
	RootComponent->bVisualizeComponent = true;

	PrimaryActorTick.bCanEverTick = true;
	RenderComponent = CreateDefaultSubobject<UAreaRenderingComponent>(TEXT("RenderComp"));
	RenderComponent->SetupAttachment(GetRootComponent());

	CubeInstance = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("CubeInstance"));
	CubeInstance->SetupAttachment(GetRootComponent());
	CubeInstance->NumCustomDataFloats = 3;

	TurnTable = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurnTable"));
	TurnTable->SetupAttachment(GetRootComponent());

	RenderTarget = UKismetRenderingLibrary::CreateRenderTarget2D(GetWorld(), 1024, 1024);
}

// Called when the game starts or when spawned
void AScanner::BeginPlay()
{
	renderSet = false;
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
		auto cubeSize = FVector(10,10,10);

		if(hit.bBlockingHit && CanAddCube(pos, cubeSize.X))
		{
			pos = hit.Location;
			auto cube = FEditorVisCube(pos, cubeSize, FColor::Emerald);
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
	CubeInstance->ClearInstances();
}

void AScanner::LineScan(FVector Start, FVector End, FVector traceDir, int numberScans)
{
	RenderComponent->Lines.Empty(numberScans);
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
			
			auto cube = FEditorVisCube(TheEnd, cubeSize, FColor::Emerald);
			if(CanAddCube(TheEnd, cubeSize.X))
			{
				//auto aColor = GetUVColorAtLocation(hit);
				//auto num =CubeInstance->AddInstance(FTransform(FRotator::ZeroRotator, TheEnd + FVector(1000,0,0), cubeSize / 100));
				//SetInstanceColor(num, aColor);
				RenderComponent->Cubes.Add(cube);
			}
		}
		
		auto line = FEditorVisLine(current, TheEnd, hit.bBlockingHit ? FColor::Green : FColor::Red);
		RenderComponent->Lines.Add(line);
		current += FVector(dir.X * increment, dir.Y * increment, dir.Z * increment);
	}
}

void AScanner::ManyScan(int numberScans)
{
	FVector startPos = GetActorLocation();
	auto Circ =(PI * 2) * 300;
	auto increment = 0;
	float zVal = 15;
	FVector Center;
	FVector Extent;

	auto totalZ = 200;
	auto firstTrace = DoATrace(startPos + FVector(0,0, 2000), startPos);
	
	if(ScanFlags & static_cast<uint8>(EScanCriteria::GetBounds) && firstTrace.GetActor())
	{
		firstTrace.GetActor()->GetActorBounds(true, Center, Extent);
		GEngine->AddOnScreenDebugMessage(1, 20, FColor::Blue, Extent.ToString());
	}

	if(ScanFlags & static_cast<uint8>(EScanCriteria::SetRenderTarget) && !renderSet)
	{
		SetRenderTarget(firstTrace);
	}
	
	for(int i = 0; i < numberScans; i++)
	{
		for(int j = 0; j < numberScans; j++)
		{
			auto aPoint = GetPointAtRotation(GetActorLocation() + FVector(0,0,zVal), increment, 300);
			DoSingleLine(aPoint,GetActorLocation() + FVector(0,0,zVal));
			increment += 360 / numberScans;
		}
		
		startPos += FVector(0,10,0);
		increment = 0;
		zVal +=  totalZ / numberScans;
	}

	if(ScanFlags & (uint8)(EScanCriteria::ClearAll))
	{
		ClearAll(10);
	}
}

void AScanner::AddCube(FVector Pos, FVector Size)
{
	auto cube = FEditorVisCube(Pos, Size, FColor::Emerald);
	RenderComponent->Cubes.Add(cube);
}

void AScanner::AddCubeWithRotation(FVector Pos, FVector Size, FRotator Rotation)
{
	auto cube = FEditorVisCube(Pos, Size, FColor::Emerald, 3, Rotation);
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

void AScanner::SetInstanceColor(int index, FLinearColor Color)
{
	auto aColor = Color.ToFColor(true);
	GEngine->AddOnScreenDebugMessage(0, 20, Color.ToFColor(true), Color.ToString());
	GEngine->AddOnScreenDebugMessage(1, 20, Color.ToFColor(false), aColor.ToString());
	CubeInstance->SetCustomDataValue(index, 0, Color.R * 1.5f);
	CubeInstance->SetCustomDataValue(index, 1, Color.G * 1.5f);
	CubeInstance->SetCustomDataValue(index, 2, Color.B * 1.5f);
	
}


FHitResult AScanner::DoATrace(FVector Start, FVector End)
{
	auto HitResult = FHitResult();
	auto Query = FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldStatic);
	GetWorld()->LineTraceSingleByObjectType(HitResult, Start, End, Query);
	
	return HitResult;
}

FHitResult AScanner::TraceByChannel(FVector Start, FVector End)
{
	auto HitResult = FHitResult();
	auto Query2 = FCollisionQueryParams(TEXT("Test"), true);
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_WorldStatic, Query2);
	return HitResult;
	
}

void AScanner::SetRenderTarget(FHitResult HitResult)
{
	TargetMaterial = Cast<UStaticMeshComponent>(HitResult.Component)->GetMaterial(0);
	DynamicMatOrg = UMaterialInstanceDynamic::Create(AddMaterial, this);
	DynamicMatScanned = UMaterialInstanceDynamic::Create(TargetMaterial, this);
	auto param = FHashedMaterialParameterInfo(TEXT("Albedo"));
	UTexture* texture = nullptr;
	DynamicMatScanned->GetTextureParameterValue(param, texture);
	DynamicMatOrg->SetTextureParameterValue(TEXT("Texture"), texture);
	//RenderTarget->ClearColor = FLinearColor(0.2f, 0.2f, 0.2f);
	UKismetRenderingLibrary::DrawMaterialToRenderTarget(GetWorld(), RenderTarget, DynamicMatOrg);
	renderSet = true;
}

void AScanner::GetHitActorBounds(FVector& Center, FVector& Extent)
{
	DoATrace(GetActorLocation() + FVector(0, 0,2000),
		GetActorLocation()).GetActor()->
	GetActorBounds(true, Center, Extent);
}

FLinearColor AScanner::GetUVColorAtLocation(FHitResult HitResult)
{
	if(!renderSet) SetRenderTarget(HitResult);
	
	FVector2d hitPos = FVector2d::ZeroVector;
	UGameplayStatics::FindCollisionUV(HitResult, 0, hitPos);
	auto color = UKismetRenderingLibrary::ReadRenderTargetRawUV(GetWorld(), RenderTarget, hitPos.X, hitPos.Y);
	return color;
}

void AScanner::GetColorAtHitPoint()
{
	
}

void AScanner::DoSingleLine(FVector Start, FVector End)
{
	
	auto HitResult = FHitResult();
	auto Query = FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldStatic);
	GetWorld()->LineTraceSingleByObjectType(HitResult, Start, End, Query);
	
	auto line = FEditorVisLine(Start,
		HitResult.bBlockingHit ? HitResult.Location : End,
		HitResult.bBlockingHit ? FColor::Green : FColor::Red);
	

	RenderComponent->Lines.Add(line);
}

FVector AScanner::GetPointAtRotation(FVector Center, float degree, float Radius)
{
	float theSin = FMath::Sin(FMath::DegreesToRadians(degree)) * Radius;
	float theCos = FMath::Cos(FMath::DegreesToRadians(degree)) * Radius;

	auto pos = Center + FVector(theCos, theSin,0);

	return pos;
}

