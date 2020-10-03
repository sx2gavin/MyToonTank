// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyToonTank/Pawns/PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;
class AProjectileBase;

/**
 * 
 */
UCLASS()
class MYTOONTANK_API APawnTank : public APawnBase
{
	GENERATED_BODY()

private:
	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", Meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	// Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", Meta = (AllowPrivateAccess = "true"))
	float MovementSpeed = 200.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", Meta = (AllowPrivateAccess = "true"))
	float AimSpeed = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", Meta = (AllowPrivateAccess = "true"))
	float TurnSpeed = 0.5f;

	FVector MoveForwardVec;
	FVector MoveRightVec;
	FRotator AimRotator;

	// Functions
	UFUNCTION()
	void CalculateMoveForward(float AxisValue);
	UFUNCTION()
	void CalculateMoveRight(float AxisValue);
	UFUNCTION()
	void CalculateAim(float AxisValue);

	void Move();
	void Aim();

public:

	APawnTank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Destruction() override;

	UFUNCTION(BlueprintImplementableEvent)
	void CreateHealthWidget();
	UFUNCTION(BlueprintImplementableEvent)
	void RemoveHealthWidget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
