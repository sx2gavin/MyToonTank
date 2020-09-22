// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "MyToonTank/Actors/ProjectileBase.h"
#include "MyToonTank/Components/HealthComponent.h"
#include "MyToonTank/GameModes/ToonTankGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);
	
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

	Health = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
}

// Called when the game starts or when spawned
void APawnBase::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentGameMode = Cast<AToonTankGameModeBase>(UGameplayStatics::GetGameMode(this));
}

void APawnBase::Fire()
{
	AProjectileBase* Projectile = GetWorld()->SpawnActor<AProjectileBase>(
		ProjectileType,
		ProjectileSpawnPoint->GetComponentLocation(),
		ProjectileSpawnPoint->GetComponentRotation());

	Projectile->SetOwner(this);
}

void APawnBase::Destruction()
{
	CurrentGameMode->ActorDied(this);
}

