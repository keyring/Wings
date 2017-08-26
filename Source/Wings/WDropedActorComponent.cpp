// Fill out your copyright notice in the Description page of Project Settings.

#include "Wings.h"
#include "WDropedActorComponent.h"
#include "WPickupItemActor.h"


// Sets default values for this component's properties
UWDropedActorComponent::UWDropedActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWDropedActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWDropedActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWDropedActorComponent::DropItems()
{
    if (DropedActorClasses.Num() <= 0) {
        return;
    }
    UWorld *TheWorld = GetWorld();
    AActor *Parent = GetOwner();

    const FRotator SpawnRotation = Parent->GetActorRotation();
    const FVector SpawnLocation = Parent->GetActorLocation();
    FActorSpawnParameters ActorParam;
    ActorParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    if (TheWorld != nullptr && Parent != nullptr) {
        for (auto Drops : DropedActorClasses) {
            if (Drops.DropItemClass == nullptr) {
                UE_LOG(WingsAttack, Log, TEXT("Actor Drop Item Failed: Not Give Drops Class!! See npc_item_drop."))
                continue;
            }
            AWPickupItemActor *Item = TheWorld->SpawnActor<AWPickupItemActor>(Drops.DropItemClass, SpawnLocation, SpawnRotation, ActorParam);
            if (Item != nullptr) {
                Item->SetItemNum(Drops.DropItemNum);
            }
           
        }
    }
}

