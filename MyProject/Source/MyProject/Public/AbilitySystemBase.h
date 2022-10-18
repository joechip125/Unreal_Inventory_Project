// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "UObject/Object.h"
#include "AbilitySystemBase.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UAbilitySystemBase : public UAbilitySystemComponent
{
	GENERATED_BODY()



public:
	UAbilitySystemBase();
	
	virtual void BeginPlay() override;

	bool GrantAbilities();

	TArray<TSubclassOf<UGameplayAbility>> GrantedAbilities;
};
