// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealExtendedPythonBPLibrary.h"
#include "UnrealExtendedPython.h"

UUnrealExtendedPythonBPLibrary::UUnrealExtendedPythonBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UUnrealExtendedPythonBPLibrary::UnrealExtendedPythonSampleFunction(float Param)
{
	return -1;
}

void UUnrealExtendedPythonBPLibrary::UnrealCallFunction(FString InString)
{
	UE_LOG(LogTemp, Error, TEXT("OutPut string %s"), *InString);
}

