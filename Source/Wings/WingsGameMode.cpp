// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Wings.h"
#include "WingsGameMode.h"
#include "WingsCharacter.h"

AWingsGameMode::AWingsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AWingsGameMode::BeginPlay()
{
	Super::BeginPlay();
	FTransform SpawnLocation;
	SpawnedActor = GetWorld()->SpawnActor<ABoom>(ABoom::StaticClass(), SpawnLocation);

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AWingsGameMode::DestroyActorFunction, 10);
}

void AWingsGameMode::DestroyActorFunction()
{
	if (SpawnedActor != nullptr){
		SpawnedActor->Destroy();
	}
}
