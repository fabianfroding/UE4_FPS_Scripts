// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PrimeFPSHUD.generated.h"

UCLASS()
class APrimeFPSHUD : public AHUD
{
	GENERATED_BODY()

public:
	APrimeFPSHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

