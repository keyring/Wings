// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WMonsterCharacter.h"
#include "WMeleeCharacter.generated.h"

UCLASS()
class WINGS_API AWMeleeCharacter : public AWMonsterCharacter
{
	GENERATED_BODY()

public:



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this character's properties
	AWMeleeCharacter();
    
    // Called every frame
	virtual void Tick(float DeltaTime) override;

    void Attack() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
};
