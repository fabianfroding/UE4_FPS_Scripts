// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimeFPS_GameMode.h"

#include "Kismet/GameplayStatics.h"

void APrimeFPS_GameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(CountDownTimerHandle, this, &APrimeFPS_GameMode::CountdownTimer, 1.0f, true, 1.0f);
}

void APrimeFPS_GameMode::RestartGameplay(bool Won)
{
	if (Won)
	{
		ResetLevel();
	}
	else
	{
		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle, this, &APrimeFPS_GameMode::ResetLevel, 3.0f);
	}
}

void APrimeFPS_GameMode::ResetLevel()
{
	UGameplayStatics::OpenLevel(GetWorld(), "Gameplay");
}

void APrimeFPS_GameMode::CountdownTimer()
{
	TimerCount--;

	if (TimerCount == 0)
	{
		GetWorldTimerManager().ClearTimer(CountDownTimerHandle);
		ResetLevel();
	}
}
