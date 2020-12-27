// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "task_GetLocToPatrol.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ANIMALSTORYGAME_API Utask_GetLocToPatrol : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public :
	Utask_GetLocToPatrol(FObjectInitializer const& obj_init);

	EBTNodeResult::Type ExecuteTask(class UBehaviorTreeComponent& owner_comp, uint8* node_memory);

	
};
