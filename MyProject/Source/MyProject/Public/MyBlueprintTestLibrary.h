// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintTestLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyBlueprintTestLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
		void Hello();

	public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "DumbValues|ReallyDumbValues")
		FVector myVector;
};
