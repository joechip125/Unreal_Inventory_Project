// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AreaRenderingComponent.h"
#include "GameFramework/Actor.h"
#include "RenderingComponentHandler.generated.h"

UCLASS()
class AIMECHANICS_API ARenderingComponentHandler : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARenderingComponentHandler();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAreaRenderingComponent* RenderComponent;

	UPROPERTY()
	uint32 NumberX;
	UPROPERTY()
	uint32 NumberY;
	UPROPERTY()
	float distanceBetween;

	UFUNCTION(BlueprintCallable)
	void SetArray(int numX, int numY, float distance, FVector start, FColor Color);

	void TraceSomething(FVector start, FVector end);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
