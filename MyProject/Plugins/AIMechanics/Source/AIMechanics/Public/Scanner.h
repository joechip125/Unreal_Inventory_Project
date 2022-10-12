// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AreaRenderingComponent.h"
#include "GameFramework/Actor.h"
#include "Scanner.generated.h"

USTRUCT()
struct FPointData
{
	GENERATED_BODY()

	UPROPERTY()
	FVector HitPoint;

	UPROPERTY()
	FVector HitRot;

	UPROPERTY()
	FVector HitScale;

	UPROPERTY()
	FColor HitColor;
	
};

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EScanCriteria : uint8
{
	None = 0 UMETA(Hidden),
	GetBounds = 1 << 1,
	SpawnCubes = 1 << 2,
	ClearAll = 1 << 3
};

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

	UFUNCTION(BlueprintCallable)
	void AddCube(FVector Pos, FVector Size);

	UFUNCTION(BlueprintCallable)
	void AddCubeWithRotation(FVector Pos, FVector Size, FRotator Rotation);
	
	UFUNCTION(BlueprintCallable)
	void GetColorAtHitPoint();

	UFUNCTION(BlueprintCallable)
	void DoSingleLine(FVector Start, FVector End);
	
	UFUNCTION(BlueprintCallable)
	FVector GetPointAtRotation(FVector Center, float degree, float Radius);

	bool CanAddCube(FVector SuggestedPos, float tolerance) const;

	void SetInstanceColor(int index, FLinearColor Color);
	
	FHitResult DoATrace(FVector Start, FVector End);

	FHitResult TraceByChannel(FVector Start, FVector End);

	void SetRenderTarget(FHitResult HitResult);

	void GetHitActorBounds(FVector& Center, FVector& Extent);
	
	FLinearColor GetUVColorAtLocation(FHitResult HitResult);

public:
	UPROPERTY()
	bool renderSet;

	UPROPERTY()
	TArray<FPointData> pointArray;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAreaRenderingComponent* RenderComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInstancedStaticMeshComponent* CubeInstance;

	UPROPERTY(VisibleAnywhere)
	UMaterialInstanceDynamic* DynamicMatOrg;

	UPROPERTY(VisibleAnywhere)
	UMaterialInstanceDynamic* DynamicMatScanned;

	UPROPERTY(VisibleAnywhere)
	UTextureRenderTarget2D* RenderTarget;

	UPROPERTY(VisibleAnywhere)
	UMaterialInterface* TargetMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInterface* AddMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* TurnTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Bitmask, BitmaskEnum = "EScanCriteria"))
	int32 ScanFlags;
};






