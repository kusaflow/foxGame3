// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionTypes.h"
#include "BaseAI.generated.h"

UCLASS()
class ANIMALSTORYGAME_API ABaseAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseAI();

	UPROPERTY(EditAnywhere, Category = "kusa_AI")
	class UAIPerceptionComponent* AI_Sight;

	class UAISenseConfig_Sight* Sense_sight;

	UPROPERTY(EditAnywhere, Category = "Path")
	TArray<FVector> pathPoint;

	UPROPERTY(EditAnywhere, Category = "movement")
	float walkVelocity = 0;
	
	UPROPERTY(EditAnywhere, Category = "movement")
	float RunVelocity =  0;


	//blackboard
	class UBlackboardComponent* bb;

	bool bisInViewRange;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "movement")
	float detectionMeter;

	int AI_detectionSpeed = 400;
	int AI_Un_detectionSpeed_fast = 500;
	int AI_Un_detectionSpeed_Slow = 100;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	///=-------------------------
	UFUNCTION()
	void Sight_Perception_Updated(AActor* Actor, FAIStimulus Stimulus);


	UFUNCTION(BlueprintCallable)
	void SetVelocity(bool bDoWalk);



};
