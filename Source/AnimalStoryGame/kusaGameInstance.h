// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "kusaGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ANIMALSTORYGAME_API UkusaGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "kusaVar")
	int anim_inst_idx = 0;
	/*	0 is normal 
		1 to openRope
	
	*/

	UPROPERTY(BlueprintReadWrite, Category = "kusaVar")
	bool bCanDisapearFood;

	UPROPERTY(BlueprintReadWrite, Category = "kusaVar")
	bool bIsCurrentFoodIsThere;
	
	//show Path when inspected
	UPROPERTY(BlueprintReadWrite, Category = "kusaVar")
		bool bshowPath = false;


	//draw new giude actor
	UPROPERTY(BlueprintReadWrite, Category = "kusaVar")
		bool bDrawGuideActor;

	//do zoom in or not
	UPROPERTY(BlueprintReadWrite, Category = "kusaVar")
		bool bDoZoomOut = false;


};
