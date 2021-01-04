// Fill out your copyright notice in the Description page of Project Settings.


#include "mainHud.h"
#include "Blueprint/UserWidget.h"
#include "screens/helpfulDataOnScreen.h"
#include "screens/eneryMeters.h"


AmainHud::AmainHud() {
	
}

void AmainHud::BeginPlay() {
	Super::BeginPlay();
	if (helper_subClass) {
		UI_helper = CreateWidget<UhelpfulDataOnScreen>(GetWorld(), helper_subClass);
	}
	
	if (UI_helper) {
		UI_helper->AddToViewport();
	}
	
}

void AmainHud::Tick(float Delta) {
	Super::Tick(Delta);

	//helper class
	if (UI_helper) {
		UI_helper->Update_Interact_progressBar();
	}

}

void AmainHud::DrawHUD() {
	Super::DrawHUD();
}


//visiblity===========================
void AmainHud::helper_Visibility_Primary(bool setV) {
	//UE_LOG(LogTemp, Warning, TEXT("ss----------------------------------------------"));
	if (UI_helper) {
		UI_helper->Visibility_Primary(setV);
	}
}


void AmainHud::helper_Visibility_InputHelpText(bool setV) {
	if (UI_helper) {
		UI_helper->Visibility_InputHelpText(setV);
	}
}


void AmainHud::helper_Visibility_interact_progressBar(bool setV) {
	if (UI_helper) {
		UI_helper->Visibility_interact_progressBar(setV);
	}

}


//set Text--------------------------------------------------------------------------
void AmainHud::helper_SetText_Primary(FText msg) {
	if (UI_helper) {
		UI_helper->SetText_Primary(msg);
	}
}

void AmainHud::helper_SetText_InputHelpText(FText msg) {
	if (UI_helper) {
		UI_helper->SetText_InputHelpText(msg);
	}
}


void AmainHud::anim_helperText(bool DoShow) {
	if (UI_helper) {
		UI_helper->Anim_PrimHelp(DoShow);
	}
}

