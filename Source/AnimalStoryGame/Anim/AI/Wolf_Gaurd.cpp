// Fill out your copyright notice in the Description page of Project Settings.


#include "Wolf_Gaurd.h"
#include "../../AI/Base/BaseAI.h"

void UWolf_Gaurd::update() {
	ABaseAI* player = Cast<ABaseAI>(TryGetPawnOwner());

	if (player) {
		AnimState = player->AnimState;
	}

}

void UWolf_Gaurd :: AnimNotif_ResetAnimState() {
	ABaseAI* player = Cast<ABaseAI>(TryGetPawnOwner());

	if (player) {
		AnimState = 0;
		player->AnimState = 0;
		player->HitScale = 1;
	}
}

void UWolf_Gaurd :: AnimNotif_AttackAnimSt() {
	ABaseAI* player = Cast<ABaseAI>(TryGetPawnOwner());

	if (player) {
		player->HitScale = 30;
	}
}
