// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

void APawnTurret::TurnToPlayerTank()
{
	if (PlayerTankInRange())
	{
		FVector PlayerTankDirection = PlayerTank->GetActorLocation() - GetActorLocation();
		FRotator NewRotation = FMath::RInterpTo(
			TurretMesh->GetComponentRotation(),
			PlayerTankDirection.Rotation(),
			GetWorld()->DeltaTimeSeconds,
			TurretTurnRate);
		TurretMesh->SetWorldRotation(NewRotation);
	}
}

bool APawnTurret::PlayerTankInRange()
{
	if (PlayerTank)
	{
		float DistToPlayerTank = FVector::Dist(GetActorLocation(), PlayerTank->GetActorLocation());
		if (DistToPlayerTank <= FireRange)
		{
			return true;
		}
	}
	return false;
}

void APawnTurret::CheckTankToFire()
{
	if (PlayerTankInRange())
	{
		Fire();
	}
}

APawnTurret::APawnTurret()
{

}

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TurnToPlayerTank();
}

void APawnTurret::Fire()
{
	Super::Fire();

	UE_LOG(LogTemp, Warning, TEXT("Fire"));
}

void APawnTurret::Destruction()
{
	Super::Destruction();

	Destroy();
}

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &APawnTurret::CheckTankToFire, 1.0f / FireRate, true);

	PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}