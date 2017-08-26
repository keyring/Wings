// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WBulletActor.h"
#include "WHandgunBulletActor.generated.h"

/**
 * 
 */
UCLASS()
class WINGS_API AWHandgunBulletActor : public AWBulletActor
{
	GENERATED_BODY()
	
	
public:
    AWHandgunBulletActor();
	
    UFUNCTION()
    void OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
};
