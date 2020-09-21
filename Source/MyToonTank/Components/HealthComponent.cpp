// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "MyToonTank/Pawns/PawnBase.h"

void UHealthComponent::OnHostTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Health > 0 && Damage > 0)
	{
		Health = FMath::Clamp(Health - Damage, 0.f, DefaultHealth);

		if (Health <= 0.f)
		{
			APawnBase* PawnBase = Cast<APawnBase>(GetOwner());
			PawnBase->Destruction();
		}
	}

}

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	Health = DefaultHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OnHostTakeDamage);
}

