// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class UProjectileMovementComponent;
class UDamageType;
class UParticleSystemComponent;

UCLASS()
class MYTOONTANK_API AProjectileBase : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* ProjectileTrailEffect;

	// Variables
	UPROPERTY(EditAnywhere, Category = "Speed")
	float ProjectileSpeed = 2000.f;
	UPROPERTY(EditAnywhere, Category = "Damage")
	float Damage = 50.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Damage", Meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UDamageType> DamageType;
	UPROPERTY(EditAnywhere, Category = "Effect")
	UParticleSystem* HitEffect;
	UPROPERTY(EditAnywhere, Category = "Effect")
	UParticleSystem* SpawnEffect;
	UPROPERTY(EditAnywhere, Category = "Effect")
	TSubclassOf<UCameraShake> HitCameraShake;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect", Meta = (AllowPrivateAccess = "true"))
	USoundBase* LaunchSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect", Meta = (AllowPrivateAccess = "true"))
	USoundBase* ExplosionSound;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit);
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
