// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WUnitBaseCharacter.generated.h"


class UAudioComponent;
class USoundCue;

UCLASS()
class WINGS_API AWUnitBaseCharacter : public ACharacter
{
	GENERATED_BODY()



public:
    // Attack

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=npc_unit_attack)
    float AttackDamageMin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=npc_unit_attack)
    float AttackDamageMax;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category=npc_unit_attack)
    float AttackRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=npc_unit_attack)
    int32 AttackSightRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=npc_unit_attack)
    int32 AttackRange; 

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category =npc_unit_attack)
    int32 AttackBaseSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=npc_unit_attack)
    int32 AttackSpeed;

    // Bounty
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=npc_unit_bounty)
    int32 BountyExp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=npc_unit_bounty)
    int32 BountyGoldMin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=npc_unit_bounty)
    int32 BountyGoldMax;

    // Movement
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=npc_unit_movement)
    float MovementSpeed;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=npc_unit_sound)
    class USoundBase *AttackSound;

    float TimeSinceLastAttack;

protected:
    float AttackDamage;

    // Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Sets default values for this character's properties
	AWUnitBaseCharacter();
    
    // Called every frame
	virtual void Tick(float DeltaTime) override;

    virtual float TakeDamage(float DamageCount, struct FDamageEvent const &DamageEvent, AController *EventInstigator, AActor *DamageCauser) override;

    virtual void Attack();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE bool IsInSightRange(int32 Distance){ return Distance < AttackSightRange; }
    FORCEINLINE bool IsInAttackRange(int32 Distance){ return Distance < AttackRange; }

protected:

    UAudioComponent * PlayAttackSound(USoundBase *Sound);
	
};
