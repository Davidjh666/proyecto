// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ProyectoGameMode.generated.h"

UCLASS(minimalapi)
class AProyectoGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AProyectoGameMode();

protected:


	virtual void BeginPlay() override;


};



