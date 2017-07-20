// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WUnitBaseCharacter.h"
#include "WMonsterCharacter.generated.h"

/**
 * 
 */
UCLASS()
class WINGS_API AWMonsterCharacter : public AWUnitBaseCharacter
{
	GENERATED_BODY()
	
protected:

    virtual void BeginPlay() override;

public:
    AWMonsterCharacter();

    virtual void Tick(float DeltaTime) override;

    virtual float TakeDamage(float DamageCount, FDamageEvent const &DamageEvent, AController *DamageInstigator, AActor *DamageCauser);
	
	
};
