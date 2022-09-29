// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIMechanics.h"

#include "AreaComponentVisualizer.h"
#include "CommanderBase.h"
#include "EnvInfo.h"
#include "UnrealEdGlobals.h"
#include "Editor/UnrealEdEngine.h"

#define LOCTEXT_NAMESPACE "FAIMechanicsModule"

void FAIMechanicsModule::StartupModule()
{
	if(GUnrealEd)
	{
		TSharedPtr<FAreaComponentVisualizer> compPtr = MakeShareable(new FAreaComponentVisualizer());
		if(compPtr.IsValid())
		{
			GUnrealEd->RegisterComponentVisualizer(ACommanderBase::StaticClass()->GetFName(), compPtr);
			compPtr->OnRegister();
		}
	}
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FAIMechanicsModule::ShutdownModule()
{
	if(GUnrealEd)
	{
		GUnrealEd->UnregisterComponentVisualizer(ACommanderBase::StaticClass()->GetFName());
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAIMechanicsModule, AIMechanics)