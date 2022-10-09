﻿// Fill out your copyright notice in the Description page of Project Settings.

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

	UFUNCTION(BlueprintCallable)
	void ClearAll(int Slack);

	UFUNCTION(BlueprintCallable)
	void LineScan(FVector Start, FVector End , FVector traceDir, int numberScans);

	void AddCube(FVector Pos, FVector Size);
	UFUNCTION(BlueprintCallable)
	void GetColorAtHitPoint();



	bool CanAddCube(FVector SuggestedPos, float tolerance) const;

	void SetInstanceColor(int index, FColor Color);
	
	FHitResult DoATrace(FVector Start, FVector End);

	FHitResult TraceByChannel(FVector Start, FVector End);

	FLinearColor GetUVColorAtLocation(FHitResult HitResult);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAreaRenderingComponent* RenderComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInstancedStaticMeshComponent* CubeInstance;

	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;

	UPROPERTY()
	UTextureRenderTarget2D* RenderTarget;
};






