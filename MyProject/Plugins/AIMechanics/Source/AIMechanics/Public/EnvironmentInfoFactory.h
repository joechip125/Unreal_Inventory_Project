// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComponentVisualizer.h"
#include "Factories/Factory.h"
#include "UObject/Object.h"
#include "EnvironmentInfoFactory.generated.h"

/**
 * 
 */
UCLASS(hidecategories=Object)
class UEnvironmentInfoFactory : public UFactory, public FComponentVisualizer
{
	GENERATED_UCLASS_BODY()
	//friend class UEnvInfo;
	
	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class,UObject* InParent,FName Name,EObjectFlags Flags,UObject* Context,FFeedbackContext* Warn) override;
	virtual bool CanCreateNew() const override;
	// End of UFactory interface	
};
