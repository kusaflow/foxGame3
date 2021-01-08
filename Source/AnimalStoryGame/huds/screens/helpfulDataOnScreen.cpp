 // Fill out your copyright notice in the Description page of Project Settings.


#include "helpfulDataOnScreen.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "../../characters/mainChar_Fox.h"
#include "Kismet/GameplayStatics.h"
#include <Animation/WidgetAnimation.h>

UhelpfulDataOnScreen::UhelpfulDataOnScreen(const FObjectInitializer& objectInit) : Super(objectInit)
{
	
}

void UhelpfulDataOnScreen::NativeConstruct()
{
	Super::NativeConstruct();
}

void UhelpfulDataOnScreen :: Update_Interact_progressBar() {
	AmainChar_Fox* fox = Cast<AmainChar_Fox>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (fox) {
		//UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD();
		interact_progressBar->SetPercent((float)fox->interact / fox->mileStone_interactVal);
	}

}

void UhelpfulDataOnScreen :: Visibility_Primary(bool setV) {
	if (setV) {
		PrimaryHelpText->SetVisibility(ESlateVisibility::Visible);
		PlayAnimation(anim_PrimaryHelper_show);
	}
	else {
		PrimaryHelpText->SetVisibility(ESlateVisibility::Hidden);
		PlayAnimation(anim_PrimaryHelper_Hide);
	}
	
}


void UhelpfulDataOnScreen::Visibility_InputHelpText(bool setV) {
	if (setV)
		InputHelpText->SetVisibility(ESlateVisibility::Visible);
	else
		InputHelpText->SetVisibility(ESlateVisibility::Hidden);
}


void UhelpfulDataOnScreen::Visibility_interact_progressBar(bool setV) {
	//UE_LOG(LogTemp, Warning, TEXT("ss----------------------------------------------"));
	if (setV)
		interact_progressBar->SetVisibility(ESlateVisibility::Visible);
	else
		interact_progressBar->SetVisibility(ESlateVisibility::Hidden);

}

//=====================================================================================


void UhelpfulDataOnScreen::SetText_Primary(FText msg) {
	PrimaryHelpText->SetText(msg);
}

void UhelpfulDataOnScreen::SetText_InputHelpText(FText msg) {
	InputHelpText->SetText(msg);
}

void UhelpfulDataOnScreen::Anim_PrimHelp(bool DoShow) {
	if (DoShow) {
		PlayAnimation(anim_PrimaryHelper_show);
	}
	else {
		PlayAnimation(anim_PrimaryHelper_Hide);
	}
}
