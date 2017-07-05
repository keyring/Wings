// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "InventoryActor.generated.h"

/**
 * 
 */
UCLASS()
class WINGS_API AInventoryActor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
    AInventoryActor();

    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

    virtual void PickUp();
    virtual void PutDown(FTransform TargetLocation);
	
	
	
};
