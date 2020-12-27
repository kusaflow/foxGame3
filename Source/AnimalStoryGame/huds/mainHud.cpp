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
	UE_LOG(LogTemp, Warning, TEXT("ss----------------------------------------------"));
	if (UI_helper) {
		UI_helper->Visibility_Primary(setV);
	}
}


void AmainHud::helper_Visibility_Secondary(bool setV) {
	if (UI_helper) {
		UI_helper->Visibility_Secondary(setV);
	}
}

void AmainHud::helper_Visibility_InstructHelper(bool setV) {
	if (UI_helper) {
		UI_helper->Visibility_InstructHelper(setV);
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

void AmainHud::helper_SetText_Secondary(FText msg) {
	if (UI_helper) {
		UI_helper->SetText_Secondary(msg);
	}
}

void AmainHud::helper_SetText_InstructHelper(FText msg) {
	if (UI_helper) {
		UI_helper->SetText_InstructHelper(msg);
	}
}
