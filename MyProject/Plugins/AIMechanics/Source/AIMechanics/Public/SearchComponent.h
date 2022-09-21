// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructContainer.h"
#include "Components/ActorComponent.h"
#include "SearchComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class AIMECHANICS_API USearchComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USearchComponent();
	
	UFUNCTION(BlueprintCallable)
	TArray<FSearchAreaStruct> GetPointGrid(FVector2D GridSize, FVector2D NumberPoints, FVector StartPoint);

	UFUNCTION(BlueprintCallable)
	void SetLargePointGrid(FVector2D GridSize, FVector2D NumberPoints, FVector StartPoint);

	UFUNCTION(BlueprintCallable)
	void SetSmallPointGrid(FVector2D GridSize, FVector2D NumberPoints, FVector StartPoint);

	UFUNCTION(BlueprintCallable)
	void CheckArrayForVisibility(TArray<FSearchAreaStruct> SearchArray, FVector AgentPos, FVector AgentForward);

	UFUNCTION(BlueprintCallable)
	float GetAngleBetweenVectors(FVector A, FVector B);

	UFUNCTION(BlueprintPure)
	FVector FindClosestFreePoint(FVector AgentPos);

	UFUNCTION(BlueprintCallable)
	void CheckGrid(FVector ObserverPos, FVector ObserverForwardVector);

	UFUNCTION(BlueprintCallable)
	bool IsPointVisible(FVector ObserverPos, FVector ObserverForwardVector, FVector Point);

	UFUNCTION(BlueprintCallable)
	void DrawDebugLines(TArray<FSearchAreaStruct> SearchArray, float Height, float Thickness);

	FColor GetColorFromEnum(ESearchPointState State);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Toggles")
	bool DrawDebugLarge;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Vectors")
	TArray<FSearchAreaStruct> LargePointArray;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Vectors")
	TArray<FSearchAreaStruct> SmallPointArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vectors", Meta = (MakeEditWidget = true))
	FVector StartingPoint;

	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	
	

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
