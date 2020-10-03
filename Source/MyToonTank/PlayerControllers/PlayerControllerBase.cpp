// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"

APlayerControllerBase::APlayerControllerBase()
{
	bShowMouseCursor = true;
}

void APlayerControllerBase::EnableDisablePlayerControl(bool bEnable)
{
	
	if (!GetPawn())
	{
		return;
	}

	if (bEnable)
	{
		GetPawn()->EnableInput(this);
		bShowMouseCursor = false;
	}
	else
	{
		GetPawn()->DisableInput(this);
		bShowMouseCursor = true;
	}
}