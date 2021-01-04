// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "helpfulDataOnScreen.generated.h"

/**
 * 
 */
UCLASS()
class ANIMALSTORYGAME_API UhelpfulDataOnScreen : public UUserWidget
{
	GENERATED_BODY()
public:
	UhelpfulDataOnScreen(const FObjectInitializer& objectInit);

	virtual void NativeConstruct() override;

	void Update_Interact_progressBar();

	UFUNCTION(BlueprintCallable, Category = "kusaText")
	void Visibility_Primary(bool setV);
	
	UFUNCTION(BlueprintCallable, Category = "kusaText")
	void Visibility_InputHelpText(bool setV);
	
	UFUNCTION(BlueprintCallable, Category = "kusaText")
	void Visibility_interact_progressBar(bool setV);
	//================================================
	UFUNCTION(BlueprintCallable, Category = "kusaText")
	void SetText_Primary(FText msg);

	UFUNCTION(BlueprintCallable, Category = "kusaText")
	void SetText_InputHelpText(FText msg);

	
	// animations
	//---Helper Text
	UFUNCTION(BlueprintCallable, Category = "kusaAnim")
	void Anim_PrimHelp(bool DoShow);



private:

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* PrimaryHelpText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* InputHelpText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* interact_progressBar;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetAnim))
	UWidgetAnimation* anim_PrimaryHelper_show;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetAnim))
	UWidgetAnimation* anim_PrimaryHelper_Hide;


};
