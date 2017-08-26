// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WPickupItemActor.h"
#include "PickupWeapon.generated.h"

UCLASS()
class WINGS_API APickupWeapon : public AWPickupItemActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	APickupWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	UFUNCTION()
    virtual void OnHit(class UPrimitiveComponent *HiComp, class AActor *OtherActor, class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) override;
	
};
