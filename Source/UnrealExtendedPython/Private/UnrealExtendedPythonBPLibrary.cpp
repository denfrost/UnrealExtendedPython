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
	UE_LOG(LogTemp, Warning, TEXT("UnrealCallFunction : %s"), *InString);
}

//Add component Bridge
UActorComponent* UUnrealExtendedPythonBPLibrary::UnrealAddComponent(TSubclassOf<class UActorComponent> ComponentClass, AActor* Actor, USceneComponent* ParentComponent, FName Name)
{

	UActorComponent* Result = nullptr;
	if (!ComponentClass.Get())
	{
		UE_LOG(LogTemp, Error, TEXT("AddComponent. ComponentClass is not valid."));
		return nullptr;
	}

	Result = NewObject<UActorComponent>(Actor, ComponentClass.Get(), Name);
	USceneComponent* AsSceneComponent = Cast<USceneComponent>(Result);
	if (AsSceneComponent)
	{
		AsSceneComponent->AttachToComponent(ParentComponent ? ParentComponent : Actor->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		FTransform T;
		AsSceneComponent->SetComponentToWorld(T);
	}
	Actor->AddInstanceComponent(Result);
	Result->OnComponentCreated();
	Result->RegisterComponent();
	Result->PostEditChange();

	Actor->RerunConstructionScripts();

	return Result;
}

//Add component Bridge
UActorComponent* UUnrealExtendedPythonBPLibrary::UnrealSubobjectDataAddComponent(TSubclassOf<class UActorComponent> ComponentClass, AActor* Actor, USceneComponent* ParentComponent, FName Name)
{
	UActorComponent* Result = nullptr;
	UE_LOG(LogTemp, Warning, TEXT("UnrealSubobjectDataAddComponent : %s"), *ComponentClass->GetName());
	return Result;
}