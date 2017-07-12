// Fill out your copyright notice in the Description page of Project Settings.

#include "Wings.h"
#include "WMeleeCharacter.h"



// Sets default values
AWMeleeCharacter::AWMeleeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



}

// Called when the game starts or when spawned
void AWMeleeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWMeleeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

// Called to bind functionality to input
void AWMeleeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AWMeleeCharacter::Attack()
{
    Super::Attack();
}

