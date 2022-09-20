// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructContainer.h"
#include "Components/ActorComponent.h"
#include "SearchComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AIMECHANICS_API USearchComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USearchComponent();
	
	UFUNCTION(BlueprintCallable)
	void GetPointGrid(FVector2d GridSize, FVector2d NumberPoints, FVector StartPoint);

	UFUNCTION(BlueprintCallable)
	float GetAngleBetweenVectors(FVector A, FVector B);

	UFUNCTION(BlueprintCallable)
	bool IsPointVisible(FVector ObserverPos, FVector ObserverForwardVector, FVector Point);

	UFUNCTION(BlueprintCallable)
	void DrawDebugLines();

	UPROPERTY(BlueprintReadWrite)
	TArray<FSearchAreaStruct> LargePointArray;

	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	
	

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
