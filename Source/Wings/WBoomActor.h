// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WBulletActor.h"
#include "WBoomActor.generated.h"

UCLASS()
class WINGS_API AWBoomActor : public AWBulletActor
{
	GENERATED_BODY()

public:	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AWBoomActor();
    
    // Called every frame
	virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
};
