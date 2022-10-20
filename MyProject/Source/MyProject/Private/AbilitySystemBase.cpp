// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystemBase.h"

UAbilitySystemBase::UAbilitySystemBase()
{
	
}

void UAbilitySystemBase::BeginPlay()
{
	Super::BeginPlay();
	

	if(!GrantAttributes())
	{
		
	}
	if(!GrantAbilities())
	{
		
	}
}

bool UAbilitySystemBase::GrantAbilities()
{
	if(GrantedAbilities.IsEmpty()) return false;
	
	for(const auto ability : GrantedAbilities)
	{
		FGameplayAbilitySpec* foundSpec = FindAbilitySpecFromClass(ability);

		if(foundSpec->Ability->GetClass() == ability) continue;
		
		
		FGameplayAbilitySpec AbilitySpec(ability);
		GiveAbility(AbilitySpec);
	}

	return true;
}

bool UAbilitySystemBase::GrantAttributes()
{
	if(GrantedAttributes.IsEmpty()) return false;

	TArray<UAttributeSet*> Sets;
	
	for(auto Attribute : GrantedAttributes)
	{
		bool exists = GetAttributeSubobject(Attribute) != nullptr;
		if(exists) continue;

		auto NewAttribute = NewObject<UAttributeSet>(GetOwner(), Attribute);
		
		NewAttribute->InitFromMetaDataTable(DTAttribute);
		//Sets.AddUnique(Attribute.GetDefaultObject());
		AddAttributeSetSubobject(NewAttribute);
	}
	
	return true;
}
