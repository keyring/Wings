// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Wings.h"
#include "WingsCharacter.h"
#include "WBulletActor.h"

AWingsCharacter::AWingsCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,230.f);
	CameraBoom->RelativeRotation = FRotator(0.f,180.f,0.f);

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, -1.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 4.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1200.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 400.f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

bool AWingsCharacter::WantsToSlide() const
{
    return bPressedSlide;
}

//////////////////////////////////////////////////////////////////////////
// Input

void AWingsCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AWingsCharacter::OnStartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AWingsCharacter::OnStopJump);
    PlayerInputComponent->BindAction("Slide", IE_Pressed, this, &AWingsCharacter::OnStartSlide);
    PlayerInputComponent->BindAction("Slide", IE_Released, this, &AWingsCharacter::OnStopSlide);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AWingsCharacter::OnFire);
    //PlayerInputComponent->BindAction("FireBoom", IE_Pressed, this, &AWingsCharacter::OnFireBoom);
	PlayerInputComponent->BindAxis("MoveRight", this, &AWingsCharacter::MoveRight);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &AWingsCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AWingsCharacter::TouchStopped);
}

void AWingsCharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

void AWingsCharacter::OnStartJump()
{
    bPressedJump = true;
}

void AWingsCharacter::OnStopJump()
{
    bPressedJump = false;
    StopJumping();
}

void AWingsCharacter::OnStartSlide()
{
    bPressedSlide = true;
}

void AWingsCharacter::OnStopSlide()
{
    bPressedSlide = false;
}

void AWingsCharacter::OnFire()
{
    if (ProjectileClass != nullptr) {
        UWorld *const World = GetWorld();
        if (World != nullptr) {

            const FRotator SpawnRotation = GetActorRotation();
            const FVector SpawnLocation = GetActorLocation();
            FActorSpawnParameters ActorParam;
            ActorParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
            World->SpawnActor<AWBulletActor>(ProjectileClass, SpawnLocation, SpawnRotation, ActorParam);
        }
    }
}

void AWingsCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void AWingsCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

