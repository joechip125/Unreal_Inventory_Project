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

TArray<FSearchAreaStruct> USearchComponent::GetPointGrid(FVector2D GridSize, FVector2D NumberPoints, FVector StartPoint)
{
	TArray<FSearchAreaStruct> Array;
	
	for (int i = 0; i < NumberPoints.X; i++)
	{
		for (int j = 0; j < NumberPoints.Y; j++)
		{
			Array.Add(FSearchAreaStruct(FVector(StartPoint.X, StartPoint.Y + (GridSize.Y * j), StartPoint.Z)));
		}
		
		StartPoint += FVector(GridSize.X, 0, 0);
	}
	
	return Array;
}

void USearchComponent::SetLargePointGrid(FVector2D GridSize, FVector2D NumberPoints, FVector StartPoint)
{
	LargePointArray = GetPointGrid(GridSize, NumberPoints, StartPoint);
}

void USearchComponent::SetSmallPointGrid(FVector2D GridSize, FVector2D NumberPoints, FVector StartPoint)
{
	SmallPointArray = GetPointGrid(GridSize, NumberPoints, StartPoint);
}

void USearchComponent::CheckArrayForVisibility(UPARAM(ref)TArray<FSearchAreaStruct> &SearchArray, FVector AgentPos, FVector AgentForward)
{
	for (auto& Point : SearchArray)
	{
		if(IsPointVisible(AgentPos, AgentForward, Point.PointPos))
		{
			Point.PointState = Clear;
			Point.PointSeen = true;
		}

		//GEngine->AddOnScreenDebugMessage(0, 3, FColor::Black, TEXT(Point.PointState));
	}
	
	DrawDebugLines(SearchArray, 100, 4);
}

float USearchComponent::GetAngleBetweenVectors(FVector A, FVector B)
{
	A.Normalize();
	B.Normalize();
	FVector::DotProduct(A, B);
	return FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(A, B)));
}

FVector USearchComponent::FindClosestFreePoint(FVector AgentPos)
{
	float Distance = 99999999;
	FVector Closest = FVector::ZeroVector;
	FSearchAreaStruct searchStruct;
	int counter = 0;
	int countHolder = 0;
	for(auto& Point : LargePointArray)
	{
		if(!Point.PointSeen)
		{
			float NewDist = FVector::Distance(Point.PointPos, AgentPos);
			if(NewDist < Distance)
			{
				Distance = NewDist;
				Closest = Point.PointPos;
				searchStruct = Point;
				countHolder = counter;
			}
		}
		
		counter++;
	}
	searchStruct.PointState = Taken;
	LargePointArray[countHolder] = searchStruct;
	
	return Closest;
}

void USearchComponent::CheckGrid(FVector ObserverPos, FVector ObserverForwardVector)
{
	for(auto& Point : LargePointArray)
	{
		if(!IsPointVisible(ObserverPos, ObserverForwardVector, Point.PointPos))
			continue;

		if(Point.PointSeen) continue;

		Point.PointSeen = true;
	}
}

bool USearchComponent::IsPointVisible(FVector ObserverPos, FVector ObserverForwardVector, FVector Point)
{
	if(FVector::Distance(ObserverPos, Point) > 1000) return false;

	if(GetAngleBetweenVectors(ObserverForwardVector, Point - ObserverPos) < 45)
	{
		FCollisionObjectQueryParams Params(FCollisionObjectQueryParams::AllStaticObjects);
		FHitResult RV_Hit(ForceInit);
		GetWorld()->LineTraceSingleByObjectType(RV_Hit, ObserverPos, Point + FVector(0,0, 5),  Params);

		if(RV_Hit.bBlockingHit) return false;

		return true;
	}
	
	return false;
}

void USearchComponent::DrawDebugLines(TArray<FSearchAreaStruct> SearchArray, float Height, float Thickness)
{
	for(auto Point : SearchArray)
	{
		DrawDebugLine(GetWorld(), Point.PointPos + FVector(0,0, Height)
			, Point.PointPos, GetColorFromEnum(Point.PointState),
			false, -1, 0, Thickness);		
	}
}

FColor USearchComponent::GetColorFromEnum(ESearchPointState State)
{
	switch (State)
	{
		case Free:
			return FColor::Red;
		case Taken:
			return FColor::Yellow;
		case Clear:
			return FColor::Green;
		default:
			return FColor::Black;
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

