// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "task_MoveTowardsThePawn.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ANIMALSTORYGAME_API Utask_MoveTowardsThePawn : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	Utask_MoveTowardsThePawn(FObjectInitializer const& obj_init);

	EBTNodeResult::Type ExecuteTask(class UBehaviorTreeComponent& owner_comp, uint8* node_memory);

	
};
