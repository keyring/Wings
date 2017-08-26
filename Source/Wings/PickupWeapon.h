// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupWeapon.generated.h"

UCLASS()
class WINGS_API APickupWeapon : public AActor
{
	GENERATED_BODY()

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=npc_item_pickup)
    class UBoxComponent *CollisionComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=npc_item_pickup)
    class UStaticMeshComponent *Mesh;

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=npc_item_pickup)
    TSubclassOf<class AWBulletActor> ItemClass;

	
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
    virtual void OnHit(class UPrimitiveComponent *HiComp, class AActor *OtherActor, class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	
};
