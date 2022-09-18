// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "Engine/StaticMeshActor.h"
#include "ItemBase.generated.h"
UCLASS()
class INVENTORY_API AItemBase : public AStaticMeshActor, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable)
	void SetOwnedGameplayTags(const FGameplayTagContainer& NewContainer);

	virtual void Tick(float DeltaTime) override;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

private:
	FGameplayTagContainer OwnedTags;
};
