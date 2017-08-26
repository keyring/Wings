// Fill out your copyright notice in the Description page of Project Settings.

#include "Wings.h"
#include "WHandgunBulletActor.h"


AWHandgunBulletActor::AWHandgunBulletActor()
{
    CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
    CollisionComp->InitSphereRadius(7.f);
    CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
    CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AWBulletActor::OnHit); // set up a notification for when this component hits something blocking
    CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
    CollisionComp->CanCharacterStepUpOn = ECB_No;
    CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
    if (MeshAsset.Object != nullptr) {
        Mesh->SetStaticMesh(MeshAsset.Object);
    }
    Mesh->SetRelativeScale3D(FVector(0.15f));
    Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    RootComponent = CollisionComp;
    Mesh->AttachTo(RootComponent);

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
    ProjectileMovement->UpdatedComponent = CollisionComp;
    ProjectileMovement->InitialSpeed = 1800.f;
    ProjectileMovement->MaxSpeed = 1800.f;
    ProjectileMovement->bRotationFollowsVelocity = false;
    ProjectileMovement->bShouldBounce = false;
    ProjectileMovement->ProjectileGravityScale = 0.f;

    // Die after 3s by default;
    InitialLifeSpan = 3.0f;

}

void AWHandgunBulletActor::OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    Super::OnHit(HitComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

}
