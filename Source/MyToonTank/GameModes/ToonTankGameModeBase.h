// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTankGameModeBase.generated.h"

class APawnBase;
class APlayerControllerBase;

/**
 * 
 */
UCLASS()
class MYTOONTANK_API AToonTankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AToonTankGameModeBase();
	void ActorDied(APawnBase* Actor);

	UFUNCTION(BlueprintCallable)
	void HandleGameStart();

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void GameStartMenu();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerHasDied);
	UFUNCTION(BlueprintImplementableEvent)
	void PlayerScoreUpdated(int32 Score);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy", Meta = (AllowPrivateAccess = "true"))
	TSubclassOf<APawnBase> EnemyPawnType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay", Meta = (AllowPrivateAccess = "true"))
	int32 StartUpDelay = 3;

	APlayerControllerBase* PlayerController;
	int32 EnemyTurretCount = 0;

	UPROPERTY(BlueprintReadOnly, Meta = (AllowPrivateAccess = "true"))
	int32 PlayerScore = 0;

	// Functions
	void HandleGameStartMenu();
	void HandleGameOver(bool PlayerHasDied);
};
