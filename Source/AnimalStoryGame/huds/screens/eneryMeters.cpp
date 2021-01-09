// Fill out your copyright notice in the Description page of Project Settings.


#include "eneryMeters.h"
#include "../../kusaGameInstance.h"
#include "Components/ProgressBar.h"
#include "../../characters/mainChar_Fox.h"
#include "Kismet/GameplayStatics.h"

UeneryMeters::UeneryMeters(const FObjectInitializer& objectInit) : Super(objectInit)
{

}

void UeneryMeters::NativeConstruct()
{
	Super::NativeConstruct();
}


void UeneryMeters ::update(float dt) {
	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	AmainChar_Fox* fox = Cast<AmainChar_Fox>(UGameplayStatics::GetPlayerPawn(GetWorld(),0));
	if (fox && gameInst) {
		if (EnergyBar)
			EnergyBar->SetPercent(fox->Energy / gameInst->EnergyLimit);
		//EnergyBar->SetPercent(0.6f);
		if (HealthBar)
			HealthBar->SetPercent(fox->Health/ gameInst->HealthLimit);


	}




	
}

