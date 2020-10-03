// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyToonTank/Pawns/PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;
class UScoreComponent;
/**
 * 
 */
UCLASS()
class MYTOONTANK_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UScoreComponent* ScoreComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", Meta = (AllowPrivateAccess = "true"))
	float FireRange = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", Meta = (AllowPrivateAccess = "true"))
	float TurretTurnRate = 10.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", Meta = (AllowPrivateAccess = "true"))
	float FireRate = 1.f; // Fire Per Second

	// Variables
	APawnTank* PlayerTank;
	FTimerHandle FireTimerHandle;

	// Functions
	void TurnToPlayerTank();
	bool PlayerTankInRange();
	void CheckTankToFire();

public:
	APawnTurret();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Fire() override;

	void Destruction() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
