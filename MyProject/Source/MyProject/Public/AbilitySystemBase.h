// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "UObject/Object.h"
#include "AbilitySystemBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthAttributeChanged, FGameplayAttribute, Attribute, float, Value);

UCLASS()
class MYPROJECT_API UAbilitySystemBase : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	UAbilitySystemBase();

	UPROPERTY(BlueprintAssignable)
	FOnHealthAttributeChanged OnHealthAttributeChanged;
	
	virtual void BeginPlay() override;

	bool GrantAbilities();

	bool GrantAttributes();

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UGameplayAbility>> GrantedAbilities;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UAttributeSet>> GrantedAttributes;

	UPROPERTY(EditDefaultsOnly)
	UDataTable* DTAttribute;

	void OnHealthChanged(FGameplayAttribute Attribute, float Value);
};
