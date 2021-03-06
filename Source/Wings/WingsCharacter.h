// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "WUnitBaseCharacter.h"
#include "WingsCharacter.generated.h"

UCLASS(config=Game)
class AWingsCharacter : public AWUnitBaseCharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

    uint32 bPressedSlide:1;

    int32 BulletNum;

public:
    /** Projectile class to spawn */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Projectile)
    TSubclassOf<class AWBulletActor> CurrentBulletClass;

    /** Projectile class to spawn */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
    TSubclassOf<class AWBulletActor> DefaultBulletClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
    TSubclassOf<class AWBoomActor> CurrentBoomClass;

protected:

	/** Called for side to side input */
	void MoveRight(float Val);

    void OnStartJump();
    void OnStopJump();
    void OnStartSlide();
    void OnStopSlide();

    void OnFire();
    void OnFireBoom();

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface


public:
	AWingsCharacter();

    bool WantsToSlide() const;

    virtual float TakeDamage(float DamageCount, struct FDamageEvent const &DamageEvent, AController *EventInstigator, AActor *DamageCauser) override;

    void SetCurrentWeapon(TSubclassOf<class AWBulletActor> BulletClass, int32 _BulletNum);

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};
