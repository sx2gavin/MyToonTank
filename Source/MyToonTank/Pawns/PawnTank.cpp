// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"

void APawnTank::CalculateMoveForward(float AxisValue)
{
	MoveForwardVec = TurretMesh->GetForwardVector() * AxisValue;
}

void APawnTank::CalculateMoveRight(float AxisValue)
{
	MoveRightVec = TurretMesh->GetRightVector() * AxisValue;
}

void APawnTank::CalculateAim(float AxisValue)
{
	AimRotator = FRotator(0.f, AxisValue * AimSpeed * GetWorld()->DeltaTimeSeconds, 0.f);
}

void APawnTank::Move()
{
	FVector MoveDirection = MoveForwardVec + MoveRightVec;
	if (MoveDirection.IsNearlyZero())
	{
		return;
	}
	MoveDirection.Normalize();
	FRotator MoveRot = MoveDirection.Rotation();

	FVector BaseForward = GetActorForwardVector();
	FRotator BaseForwardRot = BaseForward.Rotation();

	FRotator BaseRotation = FMath::RInterpTo(BaseForward.Rotation(), MoveDirection.Rotation(), GetWorld()->DeltaTimeSeconds, TurnSpeed);

	SetActorRotation(BaseRotation);

	FVector Forward = BaseRotation.Vector() * MovementSpeed * GetWorld()->DeltaTimeSeconds;
	AddActorWorldOffset(Forward, true);
}

void APawnTank::Aim()
{
	TurretMesh->AddWorldRotation(AimRotator, true);
}

APawnTank::APawnTank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(TurretMesh);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Aim();
	Move();
}

void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &APawnTank::CalculateMoveForward);
	PlayerInputComponent->BindAxis("Right", this, &APawnTank::CalculateMoveRight);
	PlayerInputComponent->BindAxis("Aim", this, &APawnTank::CalculateAim);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APawnBase::Fire);
}

void APawnTank::Destruction()
{
	Super::Destruction();
}

void APawnTank::BeginPlay()
{
	Super::BeginPlay();
}
