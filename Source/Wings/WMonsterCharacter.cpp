// Fill out your copyright notice in the Description page of Project Settings.

#include "Wings.h"
#include "WMonsterCharacter.h"
#include "WingsCharacter.h"


AWMonsterCharacter::AWMonsterCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AWMonsterCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AWMonsterCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AWingsCharacter *Player = Cast<AWingsCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
    if (!Player) {
        return;
    }

    FVector ToPlayer = Player->GetActorLocation() - GetActorLocation();
    ToPlayer.X = 0.f;
    int32 Distance = ToPlayer.Size();

    if (!IsInSightRange(Distance)) {
        return;
    }
    ToPlayer /= Distance;
    
    FRotator ToPlayerRotator = ToPlayer.Rotation();
    ToPlayerRotator.Pitch = 0;
    RootComponent->SetWorldRotation(ToPlayerRotator);

    if (IsInAttackRange(Distance)) {
        if (TimeSinceLastAttack >= (AttackRate*100.f/(AttackBaseSpeed+AttackSpeed))) {
            Attack();
            TimeSinceLastAttack = 0.f;
        }
        TimeSinceLastAttack += DeltaTime;
    } else {
        AddMovementInput(ToPlayer, MovementSpeed*DeltaTime);
        TimeSinceLastAttack = 0.f;
    }
}

float AWMonsterCharacter::TakeDamage(float DamageCount, FDamageEvent const & DamageEvent, AController * DamageInstigator, AActor * DamageCauser)
{
    float ActualDamage = Super::TakeDamage(DamageCount, DamageEvent, DamageInstigator, DamageCauser);
    StatusHealth -= ActualDamage;
    if (StatusHealth <= 0.f) {
        StatusHealth = 0.f;
        SetLifeSpan(0.1f);
    }
    return ActualDamage;
}




