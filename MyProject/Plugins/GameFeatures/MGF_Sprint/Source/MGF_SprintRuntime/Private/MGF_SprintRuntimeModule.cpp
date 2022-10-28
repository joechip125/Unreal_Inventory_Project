// Copyright Epic Games, Inc. All Rights Reserved.

#include "MGF_SprintRuntimeModule.h"

#define LOCTEXT_NAMESPACE "FMGF_SprintRuntimeModule"

void FMGF_SprintRuntimeModule::StartupModule()
{
	// This code will execute after your module is loaded into memory;
	// the exact timing is specified in the .uplugin file per-module
}

void FMGF_SprintRuntimeModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.
	// For modules that support dynamic reloading, we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMGF_SprintRuntimeModule, MGF_SprintRuntime)
