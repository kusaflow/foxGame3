// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "eneryMeters.generated.h"

/**
 * 
 */
UCLASS()
class ANIMALSTORYGAME_API UeneryMeters : public UUserWidget
{
	GENERATED_BODY()

public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UProgressBar* Energy;

	
};
