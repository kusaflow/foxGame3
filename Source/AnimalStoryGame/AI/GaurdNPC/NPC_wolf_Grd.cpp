// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_wolf_Grd.h"
#include "Components/BoxComponent.h"
#include "../../characters/mainChar_Fox.h"

ANPC_wolf_Grd :: ANPC_wolf_Grd() {

	box = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	box->SetupAttachment(GetMesh());

	box->AttachTo(GetMesh(), "HeadSocket");

	box->OnComponentBeginOverlap.AddDynamic(this, &ANPC_wolf_Grd::OnOverlapBegin);

}

void ANPC_wolf_Grd::BeginPlay()
{
	Super::BeginPlay();

	walkVelocity = 150;
	RunVelocity = 1150;

	//attackingMinDistance
	attackMinDis =  800;

	//AI Perception Sense Update
	AI_detectionSpeed = 700;
	AI_Un_detectionSpeed_fast = 1000;
	AI_Un_detectionSpeed_Slow = 100;


}


void ANPC_wolf_Grd :: OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	//------------------------------------------------------------------
	AmainChar_Fox* fox = Cast<AmainChar_Fox>(OtherActor);

	if (fox) {
		fox->Health -= 1* HitScale;
	}

}











