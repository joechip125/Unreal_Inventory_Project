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

	UFUNCTION(BlueprintCallable)
	void ClearAll(int Slack);

	UFUNCTION(BlueprintCallable)
	void LineScan(FVector Start, FVector End , FVector traceDir, int numberScans);

	UFUNCTION(BlueprintCallable)
	void ManyScan(int numberScans);

	void AddCube(FVector Pos, FVector Size);
	UFUNCTION(BlueprintCallable)
	void GetColorAtHitPoint();

	UFUNCTION(BlueprintCallable)
	FVector GetPointAtRotation(FVector Center, float degree, float Radius);

	bool CanAddCube(FVector SuggestedPos, float tolerance) const;

	void SetInstanceColor(int index, FLinearColor Color);
	
	FHitResult DoATrace(FVector Start, FVector End);

	FHitResult TraceByChannel(FVector Start, FVector End);

	void SetRenderTarget(FHitResult HitResult);

	FLinearColor GetUVColorAtLocation(FHitResult HitResult);

public:
	UPROPERTY()
	bool renderSet;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAreaRenderingComponent* RenderComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInstancedStaticMeshComponent* CubeInstance;

	UPROPERTY(VisibleAnywhere)
	UMaterialInstanceDynamic* DynamicMatOrg;

	UPROPERTY(VisibleAnywhere)
	UMaterialInstanceDynamic* DynamicMatScanned;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTextureRenderTarget2D* RenderTarget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInterface* TargetMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInterface* AddMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* TurnTable;
};






