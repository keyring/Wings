// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ActorSpawnerComponent.h"
#include "Boom.generated.h"

UCLASS()
class WINGS_API ABoom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoom();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void SpawnBullet();

public:	

	UPROPERTY()
	UStaticMeshComponent *Mesh;	

	UPROPERTY()
	UStaticMeshComponent *BoxOne;

	UPROPERTY()
	UStaticMeshComponent *BoxTwo;

	UPROPERTY()
	USceneComponent *Root;

	UPROPERTY()
	USceneComponent *ChildSceneComponent;

    UPROPERTY(EditAnywhere)
    UActorSpawnerComponent *Spawner;

	
};
