// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WBulletActor.generated.h"

UCLASS(config=Game)
class WINGS_API AWBulletActor : public AActor
{
	GENERATED_BODY()

    UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
    class USphereComponent *CollisionComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
    class UProjectileMovementComponent *ProjectileMovement;
	
public:	
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Mesh)
    class UStaticMeshComponent *Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AWBulletActor();
    
    // Called every frame
	virtual void Tick(float DeltaTime) override;
    
    UFUNCTION()
    void OnHit(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit);

    FORCEINLINE class USphereComponent *GetCollisionComp() const { return CollisionComp; }
    FORCEINLINE class UProjectileMovementComponent *GetProjectileMovement() const { return ProjectileMovement; }
	
	
};
