// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FloatMoveComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UFloatMoveComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFloatMoveComp();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Move Values")
	FVector moveValue;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Move Values")
	float moveMultiplier;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Move Values")
	bool Oscillate;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
