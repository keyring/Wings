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
        WingsHero->SetCurrentWeapon(ItemClass, ItemNum);
        UE_LOG(WingsAttack, Log, TEXT("PickupItem: %d"), ItemNum);
        Destroy();
    }
}

