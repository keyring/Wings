// Fill out your copyright notice in the Description page of Project Settings.

#include "Wings.h"
#include "WBulletActor.h"
#include "Components/SphereComponent.h"
#include "WUnitBaseCharacter.h"


// Sets default values
AWBulletActor::AWBulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWBulletActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWBulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWBulletActor::OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherActor->GetOwner() != Causer)
	{
        AWUnitBaseCharacter *UnitOtherActor = Cast<AWUnitBaseCharacter>(OtherActor);
        AWUnitBaseCharacter *UnitCauser = Cast<AWUnitBaseCharacter>(Causer);
        if (!UnitOtherActor || !UnitCauser || UnitOtherActor->GetTeamName() == UnitCauser->GetTeamName() ) {
            return;
        }
        OtherActor->TakeDamage(Damage, FDamageEvent(), nullptr, Causer);
		Destroy();
	}
}
