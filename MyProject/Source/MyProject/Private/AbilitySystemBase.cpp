// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystemBase.h"

UAbilitySystemBase::UAbilitySystemBase()
{
	
}

void UAbilitySystemBase::BeginPlay()
{
	Super::BeginPlay();
}

bool UAbilitySystemBase::GrantAbilities()
{

	for(const auto ability : GrantedAbilities)
	{
		FGameplayAbilitySpec AbilitySpec(ability);
		GiveAbility(AbilitySpec);
	}

	return !GrantedAbilities.IsEmpty();
}
