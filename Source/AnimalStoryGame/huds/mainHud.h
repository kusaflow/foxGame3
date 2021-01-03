// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "mainHud.generated.h"

/**
 * 
 */
UCLASS()
class ANIMALSTORYGAME_API AmainHud : public AHUD
{
	GENERATED_BODY()
public:

	AmainHud();

	virtual void DrawHUD() override;

	virtual void BeginPlay() override;

	virtual void Tick(float Delta) override;

	//visibilities
	UFUNCTION(BlueprintCallable)
		void helper_Visibility_Primary(bool setV);

	UFUNCTION(BlueprintCallable)
		void helper_Visibility_InputHelpText(bool setV);

	UFUNCTION(BlueprintCallable)
		void helper_Visibility_interact_progressBar(bool setV);

	//set Text---------------------------------------
	UFUNCTION(BlueprintCallable)
		void helper_SetText_Primary(FText msg);

	UFUNCTION(BlueprintCallable)
		void helper_SetText_InputHelpText(FText msg);

private:

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "kusa_UIs")
	TSubclassOf<class UUserWidget> helper_subClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "kusa_UIs")
	class UhelpfulDataOnScreen* UI_helper;
	
	
};
