// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameModeBase.h"
#include "Boom.h"
#include "WingsGameMode.generated.h"

UCLASS(minimalapi)
class AWingsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	ABoom *SpawnedActor;

public:
	AWingsGameMode();

	virtual void BeginPlay() override;

	UFUNCTION()
	void DestroyActorFunction();
};



