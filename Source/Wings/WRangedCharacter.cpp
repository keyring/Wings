// Fill out your copyright notice in the Description page of Project Settings.

#include "Wings.h"
#include "WRangedCharacter.h"
#include "WBulletActor.h"


// Sets default values
AWRangedCharacter::AWRangedCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWRangedCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWRangedCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWRangedCharacter::Attack()
{
    if (ProjectileBulletClass) {
        UWorld * const World = GetWorld();
        if (World) {
            const FRotator SpawnRotator = GetActorRotation();
            const FVector SpawnLocation = GetActorLocation();
            FActorSpawnParameters SpawnParam;
            SpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
            World->SpawnActor<AWBulletActor>(ProjectileBulletClass, SpawnLocation, SpawnRotator, SpawnParam);
        }
    }
}

// Called to bind functionality to input
void AWRangedCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

