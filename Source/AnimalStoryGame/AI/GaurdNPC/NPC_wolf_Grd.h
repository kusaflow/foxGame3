// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Base/BaseAI.h"
#include "NPC_wolf_Grd.generated.h"

/**
 * 
 */
UCLASS()
class ANIMALSTORYGAME_API ANPC_wolf_Grd : public ABaseAI
{
	GENERATED_BODY()
public:
	ANPC_wolf_Grd();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
