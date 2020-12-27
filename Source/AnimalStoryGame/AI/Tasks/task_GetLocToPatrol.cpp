// Fill out your copyright notice in the Description page of Project Settings.


#include "task_GetLocToPatrol.h"
#include <BehaviorTree/BlackboardComponent.h>
#include <BehaviorTree/BehaviorTreeComponent.h>
#include "../Base/AI_Controller.h"
#include "../Base/BaseAI.h"


Utask_GetLocToPatrol :: Utask_GetLocToPatrol(FObjectInitializer const& obj_init) {
	NodeName = "GetPointToMove";
}

EBTNodeResult::Type Utask_GetLocToPatrol :: ExecuteTask(class UBehaviorTreeComponent& owner_comp, uint8* node_memory) {

	AAI_Controller *aic = Cast<AAI_Controller>(owner_comp.GetAIOwner());
	UBlackboardComponent* bb = aic->GetBlackboardComponent();

	ABaseAI* baseAi = Cast<ABaseAI>(aic->GetPawn());

	if (!baseAi)
		return EBTNodeResult::Aborted;

	int arraySize = baseAi->pathPoint.Num();

	int idx = bb->GetValueAsInt("idx_LocToMove");
	idx++;
	idx %= arraySize;

	FVector newLoc = baseAi->pathPoint[idx];

	bb->SetValueAsInt("idx_LocToMove", idx);
	bb->SetValueAsVector("TargetLocToMove", newLoc);

	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);

	return EBTNodeResult::Succeeded;
}

