// Fill out your copyright notice in the Description page of Project Settings.

#include "Wings.h"
#include "WBoomActor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AWBoomActor::AWBoomActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
    CollisionComp->InitSphereRadius(0.5f);
    CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
    CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AWBoomActor::OnHit); // set up a notification for when this component hits something blocking
    CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
    CollisionComp->CanCharacterStepUpOn = ECB_No;

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
    ProjectileMovement->UpdatedComponent = CollisionComp;
    ProjectileMovement->InitialSpeed = 1000.f;
    ProjectileMovement->ProjectileGravityScale = 2.f;
    ProjectileMovement->MaxSpeed = 1000.f;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
    if (MeshAsset.Object != nullptr) {
        Mesh->SetStaticMesh(MeshAsset.Object);
    }
    Mesh->SetRelativeScale3D(FVector(0.25f));
    Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    
    RootComponent = CollisionComp;
    Mesh->AttachTo(RootComponent);

    InitialLifeSpan = 3.0f;


}

// Called when the game starts or when spawned
void AWBoomActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWBoomActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWBoomActor::OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    Super::OnHit(HitComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

