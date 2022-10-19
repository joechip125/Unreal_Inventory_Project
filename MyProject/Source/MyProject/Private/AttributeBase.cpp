// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeBase.h"

#include "Net/UnrealNetwork.h"


void UAttributeBase::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeBase, Health, OldHealth)
}

void UAttributeBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeBase, Health, COND_None, REPNOTIFY_Always)
}

void UAttributeBase::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if(Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, 100);
	}
}
