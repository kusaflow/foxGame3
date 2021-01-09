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
	UeneryMeters(const FObjectInitializer& objectInit);

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UProgressBar* EnergyBar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UProgressBar* HealthBar;

	float Curr_Energy;


public:
	 void update(float dt);
	
};
