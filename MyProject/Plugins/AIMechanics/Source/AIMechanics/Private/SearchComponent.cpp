// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchComponent.h"

#include <stdbool.h>


// Sets default values for this component's properties
USearchComponent::USearchComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void USearchComponent::GetPointGrid(FVector2D GridSize, FVector2D NumberPoints, FVector StartPoint)
{
	TArray<FVector> Array;
	
	for (int i = 0; i < NumberPoints.X; i++)
	{
		for (int j = 0; j < NumberPoints.Y; j++)
		{
			Array.Add(FVector(StartPoint.X, StartPoint.Y + (GridSize.Y * j), StartPoint.Z));
		}
		
		StartPoint += FVector(GridSize.X, 0, 0);
	}
}

float USearchComponent::GetAngleBetweenVectors(FVector A, FVector B)
{
	A.Normalize();
	B.Normalize();
	return FMath::RadiansToDegrees(FMath::Acos(A.Dot(B)));
}

void USearchComponent::CheckGrid(FVector ObserverPos, FVector ObserverForwardVector)
{
	for(auto & [PointPos, PointSeen] : LargePointArray)
	{
		if(!IsPointVisible(ObserverPos, ObserverForwardVector, PointPos))
			continue;

		if(PointSeen) continue;

		PointSeen = true;
	}
}

bool USearchComponent::IsPointVisible(FVector ObserverPos, FVector ObserverForwardVector, FVector Point)
{
	if(FVector::Distance(ObserverPos, Point) > 1000) return false;
	
	FCollisionObjectQueryParams Params;
	FHitResult RV_Hit(ForceInit);
	
	GetWorld()->LineTraceSingleByObjectType(RV_Hit, ObserverPos, Point,  Params);

	if(GetAngleBetweenVectors(ObserverForwardVector, ObserverPos - Point) < 45)
		return true;
	
	return false;
}

void USearchComponent::DrawDebugLines(TArray<FSearchAreaStruct> SearchArray, float Height, float Thickness)
{
	for(auto [PointPos, PointSeen] : SearchArray)
	{
		DrawDebugLine(GetWorld(), PointPos + FVector(0,0, Height)
			, PointPos, PointSeen ? FColor::Green : FColor::Red,
			false, -1, 0, Thickness);		
	}
}


// Called when the game starts
void USearchComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USearchComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

