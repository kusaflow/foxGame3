// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Wolf_Gaurd.generated.h"

/**
 * 
 */
UCLASS()
class ANIMALSTORYGAME_API UWolf_Gaurd : public UAnimInstance
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "AnimProperty")
		void update();

	UFUNCTION(BlueprintCallable, Category = "AnimProperty")
		void AnimNotif_ResetAnimState();

	UFUNCTION(BlueprintCallable, Category = "AnimProperty")
		void AnimNotif_AttackAnimSt();


	//==============Variable================

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "kusaVar")
		int AnimState;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "kusaVar")
		float velX;
	
};
