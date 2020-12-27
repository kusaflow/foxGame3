// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_wolf_Grd.h"

ANPC_wolf_Grd :: ANPC_wolf_Grd() {
	
}

void ANPC_wolf_Grd::BeginPlay()
{
	Super::BeginPlay();

	walkVelocity = 150;
	RunVelocity = 1150;

	//AI Perception Sense Update
	AI_detectionSpeed = 700;
	AI_Un_detectionSpeed_fast = 1000;
	AI_Un_detectionSpeed_Slow = 100;

}