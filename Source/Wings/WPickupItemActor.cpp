// Fill out your copyright notice in the Description page of Project Settings.

#include "Wings.h"
#include "WPickupItemActor.h"


// Sets default values
AWPickupItemActor::AWPickupItemActor():ItemNum(1)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
    CollisionComp->BodyInstance.SetCollisionProfileName("PickupItem");
    CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AWPickupItemActor::OnHit);
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
}

// Called when the game starts or when spawned
void AWPickupItemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWPickupItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWPickupItemActor::SetItemNum(int32 Num)
{
    ItemNum = Num;
}
//
//void AWPickupItemActor::OnHit(UPrimitiveComponent * HiComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
//{
//    if ((OtherActor != nullptr) && (OtherActor != this)) {
//        Destroy();
//    }
//}

