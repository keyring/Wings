// Fill out your copyright notice in the Description page of Project Settings.

#include "Wings.h"
#include "InventoryActor.h"


AInventoryActor::AInventoryActor():Super()
{
    PrimaryActorTick.bCanEverTick = true;

    auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
    if (MeshAsset.Object != nullptr) {
        GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
        GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
    }
    GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
    SetActorEnableCollision(true);
}

void AInventoryActor::BeginPlay()
{
    Super::BeginPlay();
}

void AInventoryActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AInventoryActor::PickUp()
{
    SetActorTickEnabled(false);
    SetActorHiddenInGame(true);
    SetActorEnableCollision(false);
}

void AInventoryActor::PutDown(FTransform TargetLocation)
{
    SetActorTickEnabled(true);
    SetActorHiddenInGame(false);
    SetActorEnableCollision(true);
    SetActorLocation(TargetLocation.GetLocation());
}
