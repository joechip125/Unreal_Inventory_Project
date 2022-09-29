// Fill out your copyright notice in the Description page of Project Settings.


#include "EquippedObjectComponent.h"

#include "GameFramework/Character.h"

bool UEquippedObjectComponent::EquipItem(UItemEquip* ItemTo)
{
	EquippedItem = ItemTo;
	auto charac = Cast<ACharacter>(GetOwner());
	
	if(charac)
	{
		charac->PlayAnimMontage(EquippedItem->EquipMontage);
		SetStaticMesh(EquippedItem->ObjectMesh);
		this->AttachToComponent(charac->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, EquippedItem->AttachSlot);
	}
	
	return true;
}
