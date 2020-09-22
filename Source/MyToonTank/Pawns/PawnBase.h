// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UStaticMeshComponent;
class UCapsuleComponent;
class USceneComponent;
class AProjectileBase;
class UHealthComponent;
class AToonTankGameModeBase;

UCLASS()
class MYTOONTANK_API APawnBase : public APawn
{
	GENERATED_BODY()

protected:
	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", Meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UHealthComponent* Health;

	// Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", Meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AProjectileBase> ProjectileType;

	AToonTankGameModeBase* CurrentGameMode;

public:
	// Sets default values for this pawn's properties
	APawnBase();

	virtual void Fire();

	virtual void Destruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
