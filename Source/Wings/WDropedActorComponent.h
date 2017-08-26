// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WDropedActorComponent.generated.h"

USTRUCT()
struct FDropItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=npc_item_drop)
    TSubclassOf<class AWPickupItemActor> DropItemClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=npc_item_drop)
    int32 DropItemNum;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WINGS_API UWDropedActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=npc_item_drop)
    TArray<struct FDropItem> DropedActorClasses;

public:	
	// Sets default values for this component's properties
	UWDropedActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    
    void DropItems();
		
	
};
