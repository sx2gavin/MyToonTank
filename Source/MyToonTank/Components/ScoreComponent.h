// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScoreComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYTOONTANK_API UScoreComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", Meta = (AllowPrivateAccess = "true"))
	int32 ScorePoint = 100;

public:	
	// Sets default values for this component's properties
	UScoreComponent();

	int32 GetScorePoint();
};
