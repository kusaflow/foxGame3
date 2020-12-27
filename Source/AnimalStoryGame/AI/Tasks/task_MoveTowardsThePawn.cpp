// Fill out your copyright notice in the Description page of Project Settings.


#include "task_MoveTowardsThePawn.h"
#include <BehaviorTree/BlackboardComponent.h>
#include <BehaviorTree/BehaviorTreeComponent.h>
#include "../Base/AI_Controller.h"
#include "../Base/BaseAI.h"
#include <Kismet/GameplayStatics.h>

Utask_MoveTowardsThePawn :: Utask_MoveTowardsThePawn(FObjectInitializer const& obj_init) {
	NodeName = "Move To Attack Pawn";
}

EBTNodeResult::Type Utask_MoveTowardsThePawn::ExecuteTask(class UBehaviorTreeComponent& owner_comp, uint8* node_memory) {
	AAI_Controller* aic = Cast<AAI_Controller>(owner_comp.GetAIOwner());
	UBlackboardComponent* bb = aic->GetBlackboardComponent();

	ABaseAI* baseAi = Cast<ABaseAI>(aic->GetPawn());
	
	FVector TargetLoc = UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorLocation();

	aic->MoveToLocation(TargetLoc);

	return EBTNodeResult::Succeeded;
}

