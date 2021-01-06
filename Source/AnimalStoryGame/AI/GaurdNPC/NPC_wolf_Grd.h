// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Base/BaseAI.h"
#include "NPC_wolf_Grd.generated.h"

/**
 * 
 */
UCLASS()
class ANIMALSTORYGAME_API ANPC_wolf_Grd : public ABaseAI
{
	GENERATED_BODY()
public:
	ANPC_wolf_Grd();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "kusa")
		class UBoxComponent* box;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
