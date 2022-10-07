// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AreaRenderingComponent.h"
#include "GameFramework/Actor.h"
#include "Scanner.generated.h"

UCLASS()
class AIMECHANICS_API AScanner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AScanner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void CircleScan(FVector Center, float Radius, int numberScans);
	
	void DoATrace(FVector Start, FVector End);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAreaRenderingComponent* RenderComponent;
};
