// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTankGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "MyToonTank/Pawns/PawnBase.h"
#include "MyToonTank/Pawns/PawnTank.h"
#include "MyToonTank/Pawns/PawnTurret.h"
#include "MyToonTank/PlayerControllers/PlayerControllerBase.h"
#include "MyToonTank/Components/ScoreComponent.h"

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
		UScoreComponent* TurretScore = Turret->FindComponentByClass<UScoreComponent>();

		if (TurretScore)
		{
			PlayerScore += TurretScore->GetScorePoint();
			PlayerScoreUpdated(PlayerScore);
			// UE_LOG(LogTemp, Warning, TEXT("Score: %d"), PlayerScore);
		}

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

	HandleGameStartMenu();
}

void AToonTankGameModeBase::HandleGameStart()
{
	PlayerController->EnableDisablePlayerControl(true);
	APawnTank* PawnTank = Cast<APawnTank>(PlayerController->GetPawn());
	if (PawnTank)
	{
		PawnTank->CreateHealthWidget();
	}

	GameStart();
}

void AToonTankGameModeBase::HandleGameStartMenu()
{
	TArray<AActor*> EnemyArray;
	UGameplayStatics::GetAllActorsOfClass(this, EnemyPawnType, EnemyArray);
	EnemyTurretCount = EnemyArray.Num();

	PlayerController = Cast<APlayerControllerBase>(UGameplayStatics::GetPlayerController(this, 0));
	PlayerController->EnableDisablePlayerControl(false);

	PlayerScore = 0;

	GameStartMenu();
}

void AToonTankGameModeBase::HandleGameOver(bool PlayerHasDied)
{
	PlayerController->bShowMouseCursor = true;
	GameOver(PlayerHasDied);
}
