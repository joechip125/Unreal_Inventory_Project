#pragma once

#include "ItemPDA.h"
#include "InventoryStructs.generated.h"

USTRUCT(BlueprintType)
struct FItems
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	float durability;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UItemPDA* item;

	FGuid ID;

	bool operator ==(const FItems& other) const
	{
		return this->ID == other.ID;
	}
};