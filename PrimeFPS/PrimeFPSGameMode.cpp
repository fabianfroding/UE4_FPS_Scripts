// Copyright Epic Games, Inc. All Rights Reserved.

#include "PrimeFPSGameMode.h"
#include "PrimeFPSHUD.h"
#include "PrimeFPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

APrimeFPSGameMode::APrimeFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APrimeFPSHUD::StaticClass();
}
