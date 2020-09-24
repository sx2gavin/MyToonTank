// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"


void APlayerControllerBase::EnableDisablePlayerControl(bool bEnable)
{
	
	if (!GetPawn())
	{
		return;
	}

	if (bEnable)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}
}