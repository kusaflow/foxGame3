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

	UFUNCTION(BlueprintCallable)
	void Visibility_Primary(bool setV);
	
	UFUNCTION(BlueprintCallable)
	void Visibility_Secondary(bool setV);
	
	UFUNCTION(BlueprintCallable)
	void Visibility_InstructHelper(bool setV);

	UFUNCTION(BlueprintCallable)
	void Visibility_interact_progressBar(bool setV);
	//================================================
	UFUNCTION(BlueprintCallable)
	void SetText_Primary(FText msg);

	UFUNCTION(BlueprintCallable)
	void SetText_Secondary(FText msg);
	
	UFUNCTION(BlueprintCallable)
	void SetText_InstructHelper(FText msg);
	
private:

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* InstructHelper;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* PrimaryHelpText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* SecondaryHelpText;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* interact_progressBar;
	
};
