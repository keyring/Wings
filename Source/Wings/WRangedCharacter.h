// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WUnitBaseCharacter.h"
#include "WRangedCharacter.generated.h"

UCLASS()
class WINGS_API AWRangedCharacter : public AWUnitBaseCharacter
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Projectile)
    TSubclassOf<class AWBulletActor> ProjectileBulletClass;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this character's properties
	AWRangedCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

    void Attack();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
