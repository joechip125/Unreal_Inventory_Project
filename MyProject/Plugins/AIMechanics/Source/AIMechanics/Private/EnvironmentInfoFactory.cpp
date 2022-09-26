// Fill out your copyright notice in the Description page of Project Settings.


#include "EnvironmentInfoFactory.h"

#include "EnvInfo.h"


UEnvironmentInfoFactory::UEnvironmentInfoFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UEnvInfo::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}

UObject* UEnvironmentInfoFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn)
{
	check(Class->IsChildOf(UEnvInfo::StaticClass()));
	return NewObject<UEnvInfo>(InParent, Class, Name, Flags);
}

bool UEnvironmentInfoFactory::CanCreateNew() const
{
	return true;
}
