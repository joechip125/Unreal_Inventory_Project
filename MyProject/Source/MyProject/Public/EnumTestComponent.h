// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyUserDefinedEnum.h"
#include "Components/ActorComponent.h"
#include "EnumTestComponent.generated.h"

//ECharacterQualities operator&(ECharacterQualities lhs, ECharacterQualities rhs)
//{
//	return static_cast<ECharacterQualities>
//	(static_cast<std::underlying_type_t<ECharacterQualities>>(lhs) &
//		static_cast<std::underlying_type_t<ECharacterQualities>>(rhs));
//}



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UEnumTestComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnumTestComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Bitmask, BitmaskEnum = ECharacterQualities))
	int32 QualityFlags;

	//UFUNCTION(BlueprintCallable)
	//bool IsMatch(UPARAM(meta = (Bitmask, BitmaskEnum = EAnimDescriptorFlags)) int32 Bitmask);

	
	//UFUNCTION(BlueprintCallable)
	////bool IsTall() const
	////{
	////	return QualityFlags & ECharacterQualities::TALL;
	//}

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
