// Fill out your copyright notice in the Description page of Project Settings.

#include "Wings.h"
#include "PickupWeapon.h"
#include "WBoomActor.h"
#include "WingsCharacter.h"


// Sets default values
APickupWeapon::APickupWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
    CollisionComp->BodyInstance.SetCollisionProfileName("PickupItem");
    CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &APickupWeapon::OnHit);
    CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
    CollisionComp->CanCharacterStepUpOn = ECB_No;
    CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
     
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
    if (MeshAsset.Object != nullptr) {
        Mesh->SetStaticMesh(MeshAsset.Object);
    }
    Mesh->SetRelativeScale3D(FVector(0.15f));
    Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    RootComponent = CollisionComp;
    Mesh->AttachTo(RootComponent);

    ItemClass = AWBoomActor::StaticClass();

}

// Called when the game starts or when spawned
void APickupWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickupWeapon::OnHit(UPrimitiveComponent * HiComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    if ((OtherActor != nullptr) && (OtherActor != this )) {
        AWingsCharacter *WingsHero = Cast<AWingsCharacter>(OtherActor);
        if (!WingsHero) {
            return;        
        }
        WingsHero->SetCurrentWeapon(ItemClass);
        Destroy();
    }
}

