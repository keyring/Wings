// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "WBulletActor.generated.h"

UCLASS(config=Game)
class WINGS_API AWBulletActor : public AActor
{
	GENERATED_BODY()

protected:

    UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
    class USphereComponent *CollisionComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
    class UProjectileMovementComponent *ProjectileMovement;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Mesh)
    class UStaticMeshComponent *Mesh;

    float Damage;
    AActor *Causer;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AWBulletActor();
    
    // Called every frame
	virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void SetDamage(float Value) { Damage = Value; }

    UFUNCTION()
    float GetDamage() { return Damage; }

    UFUNCTION()
    void SetCauser(AActor *F){ Causer = F; }

    UFUNCTION()
    AActor *GetCauser(){ return Causer; }
    
    UFUNCTION()
    virtual void OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    FORCEINLINE class USphereComponent *GetCollisionComp() const { return CollisionComp; }
    FORCEINLINE class UProjectileMovementComponent *GetProjectileMovement() const { return ProjectileMovement; }
	
	
};
