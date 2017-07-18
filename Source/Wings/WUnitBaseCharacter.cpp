// Fill out your copyright notice in the Description page of Project Settings.

#include "Wings.h"
#include "WUnitBaseCharacter.h"
#include "WingsCharacter.h"

// Sets default values
AWUnitBaseCharacter::AWUnitBaseCharacter()
    :AttackDamage(0.f)
    ,AttackDamageMin(10.f)
    ,AttackDamageMax(15.f)
    ,AttackRate(1.0f)
    ,AttackSightRange(300)
    ,AttackRange(100)
    ,AttackBaseSpeed(100)
    ,AttackSpeed(0)
    ,BountyExp(20)
    ,BountyGoldMin(20)
    ,BountyGoldMax(35)
    ,MovementSpeed(300.f)
    ,TimeSinceLastAttack(0.f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, -1.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 4.f;
	GetCharacterMovement()->AirControl = 0.70f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;
	GetCharacterMovement()->MaxFlySpeed = MovementSpeed;
}

// Called when the game starts or when spawned
void AWUnitBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWUnitBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    AWingsCharacter *Player = Cast<AWingsCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
    if (!Player) {
        return;
    }

    FVector ToPlayer = Player->GetActorLocation() - GetActorLocation();
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

float AWUnitBaseCharacter::TakeDamage(float DamageCount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
    float ActualDamaeg = Super::TakeDamage(DamageCount, DamageEvent, EventInstigator, DamageCauser);
    UE_LOG(WingsAttack, Log, TEXT("recieve attack damage %f"), ActualDamaeg);
    return 0.0f;
}

// Called to bind functionality to input
void AWUnitBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAudioComponent * AWUnitBaseCharacter::PlayAttackSound(USoundBase * Sound)
{
    UAudioComponent *AC = nullptr;
    if (Sound) {
        AC = UGameplayStatics::SpawnSoundAttached(Sound, GetRootComponent());
    }
    return AC;
}

void AWUnitBaseCharacter::Attack()
{
    AttackDamage = FMath::RandRange(AttackDamageMin, AttackDamageMax);
    PlayAttackSound(AttackSound);
    UE_LOG(WingsAttack, Log, TEXT("send attack damage %f"), AttackDamage);
}


