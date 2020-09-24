// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTankGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "MyToonTank/Pawns/PawnBase.h"
#include "MyToonTank/Pawns/PawnTank.h"
#include "MyToonTank/Pawns/PawnTurret.h"
#include "MyToonTank/PlayerControllers/PlayerControllerBase.h"

AToonTankGameModeBase::AToonTankGameModeBase()
{
}

void AToonTankGameModeBase::ActorDied(APawnBase* Actor)
{
	UE_LOG(LogTemp, Warning, TEXT("%s died"), *(Actor->GetName()));

	if (APawnTank* PlayerTank = Cast<APawnTank>(Actor))
	{
		HandleGameOver(true);
	}
	else if (APawnTurret* Turret = Cast<APawnTurret>(Actor))
	{
		EnemyTurretCount--;
		if (EnemyTurretCount <= 0)
		{
			HandleGameOver(false);
		}
	}
}

void AToonTankGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
}

void AToonTankGameModeBase::HandleGameStart()
{
	TArray<AActor*> EnemyArray;
	UGameplayStatics::GetAllActorsOfClass(this, EnemyPawnType, EnemyArray);
	EnemyTurretCount = EnemyArray.Num();

	APlayerControllerBase* PlayerController = Cast<APlayerControllerBase>(UGameplayStatics::GetPlayerController(this, 0));
	PlayerController->EnableDisablePlayerControl(false);

	FTimerHandle EnablePlayerHandle;
	FTimerDelegate EnablePlayerDelegate = FTimerDelegate::CreateUObject(PlayerController, &APlayerControllerBase::EnableDisablePlayerControl, true);

	GetWorld()->GetTimerManager().SetTimer(EnablePlayerHandle, EnablePlayerDelegate, StartUpDelay, false);

	GameStart();
}

void AToonTankGameModeBase::HandleGameOver(bool PlayerHasDied)
{
	GameOver(PlayerHasDied);
}
