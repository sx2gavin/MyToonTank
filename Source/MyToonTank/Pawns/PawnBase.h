// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UStaticMeshComponent;
class UCapsuleComponent;
class USceneComponent;

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

public:
	// Sets default values for this pawn's properties
	APawnBase();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Fire();

	virtual void Destruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
