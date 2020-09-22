// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTankGameModeBase.generated.h"

class APawnBase;

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

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerHasDied);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy", Meta = (AllowPrivateAccess = "true"))
	TSubclassOf<APawnBase> EnemyPawnType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay", Meta = (AllowPrivateAccess = "true"))
	int32 StartUpDelay = 3;

	int32 EnemyTurretCount = 0;

	// Functions
	void HandleGameStart();
	void HandleGameOver(bool PlayerHasDied);
};
