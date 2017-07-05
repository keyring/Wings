// Fill out your copyright notice in the Description page of Project Settings.

#include "Wings.h"
#include "Boom.h"


// Sets default values
ABoom::ABoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	ChildSceneComponent = CreateDefaultSubobject<USceneComponent>("ChildSceneComponent");
	BoxOne = CreateDefaultSubobject<UStaticMeshComponent>("BoxOne");
	BoxTwo = CreateDefaultSubobject<UStaticMeshComponent>("BoxTwo");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
    Spawner = CreateDefaultSubobject<UActorSpawnerComponent>("Spawner");

	auto BoxAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if(BoxAsset.Object != nullptr){
		BoxOne->SetStaticMesh(BoxAsset.Object);
		BoxTwo->SetStaticMesh(BoxAsset.Object);
	}
	
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	if (MeshAsset.Object != nullptr){
		Mesh->SetStaticMesh(MeshAsset.Object);
	}

    FAttachmentTransformRules AttachmentRules(EAttachmentRule::KeepRelative, false);

	RootComponent = Root;
	BoxOne->AttachToComponent(Root, AttachmentRules);
	Mesh->AttachToComponent(Root, AttachmentRules);
	ChildSceneComponent->AttachToComponent(Root, AttachmentRules);
	BoxTwo->AttachToComponent(ChildSceneComponent, AttachmentRules);
    Spawner->AttachToComponent(ChildSceneComponent, AttachmentRules);

	Mesh->SetRelativeTransform(FTransform(FRotator(30,0,0), FVector(0,100,0), FVector(0.5f)));
	ChildSceneComponent->SetRelativeTransform(FTransform(FRotator(0,0,0), FVector(250,0,0), FVector(0.1f)));
}

// Called when the game starts or when spawned
void ABoom::BeginPlay()
{
	Super::BeginPlay();

    FTimerHandle SpawnerTimer;
    GetWorldTimerManager().SetTimer(SpawnerTimer, this, &ABoom::SpawnBullet, 2, true );
	
}

// Called every frame
void ABoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABoom::SpawnBullet()
{
    Spawner->Spawn();
}
