// Fill out your copyright notice in the Description page of Project Settings.


#include "mainChar_Fox.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Math/UnrealMathUtility.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"
#include "../Anim/Fox_AnimInstance.h"
#include "../kusaGameInstance.h" 	
#include "Components/CapsuleComponent.h"
#include "Engine/EngineTypes.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Sight.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AmainChar_Fox::AmainChar_Fox()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	cameraBoom->SetupAttachment(GetRootComponent());
	cameraBoom->bDoCollisionTest = false;
	cameraBoom->TargetArmLength = 800;
	cameraBoom->SocketOffset = FVector(0.f, 0.f, 0.f);
	//cameraBoom->SetRelativeRotation(FRotator(-20, -70, 0.f));
	//cameraBoom->RelativeRotation = FRotator(0.f, 0.f, 0.f);
	//cameraBoom->bUsePawnControlRotation = false;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName);

	//Ai==============================
	Ai_percep_stim = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("AI_Perception_Stimuli"));


}

// Called when the game starts or when spawned
void AmainChar_Fox::BeginPlay()
{
	Super::BeginPlay();

	//RootComponent->AddLocalRotation(FRotator(0, 60, 0));
	
	bisDead = false;
	

	
}

// Called every frame
void AmainChar_Fox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());


	if (GetCharacterMovement()->MaxWalkSpeed < VelShouldBe) {
		GetCharacterMovement()->MaxWalkSpeed += 800 * DeltaTime;
	}
	else if (GetCharacterMovement()->MaxWalkSpeed > VelShouldBe) {
		GetCharacterMovement()->MaxWalkSpeed -= 800 * DeltaTime;
	}

	
	//animInst index set
	AnimInst_Idx = gameInst->anim_inst_idx;
	

	if (GetVelocity().Size() != 0) {}
		//GetMesh()->SetRelativeLocation(InitMeshRelativeLoc);

	
	//interact CoolDown
	if (interact > 0) {
		interact -= 130 * DeltaTime;
	}
	else if (interact <= 0) {
		interact = 0;
	}

	//velocivty change
	if (!bIsCrouching && !bIsWalking)
		VelShouldBe = 1000;
	else
		VelShouldBe = 200;


	//state change check
	if (do_changeState_at_mileStone) {
		if (interact >= mileStone_interactVal) {
			do_changeState_at_mileStone = false;
			if (playCineMetic) {
				playAnimation();
			}
			
			disableInput_camera = AMS_disableInput_camera;
			disableInput_interact = AMS_disableInput_interact;
			disableInput_movement = AMS_disableInput_movement;

			AnimInst_Idx = AMS_animInst;
			gameInst->anim_inst_idx = AMS_animInst;

			cameraBoom->TargetArmLength = AMS_armLength;
			cameraBoom->SetRelativeRotation(AMS_CameraRot);
			
			
		}
	}

	//Dead Animation For CameraBoom
	if (bisDead) {
		cameraBoom->TargetArmLength += 500* DeltaTime;
		
	}

	//zoom in or not
	if (!bisDead) {
		if (gameInst->bDoZoomOut) {
			if (cameraBoom->TargetArmLength < 2000)
				cameraBoom->TargetArmLength += 3000*DeltaTime;
			//cameraBoom->ProbeChannel = ECollisionChannel::ECC_Camera;
			//cameraBoom->bDoCollisionTest = false;
		}
		else {
			if (cameraBoom->TargetArmLength > 800)
				cameraBoom->TargetArmLength -= 500 * DeltaTime;
			//cameraBoom->TargetArmLength = 800;
			//cameraBoom->ProbeChannel = ECollisionChannel::ECC_WorldStatic;
			//cameraBoom->bDoCollisionTest = true;
		}
	}

		
	
}

// Called to bind functionality to input
void AmainChar_Fox::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
	PlayerInputComponent->BindAxis("forward", this, &AmainChar_Fox::moveForward);
	PlayerInputComponent->BindAxis("moveLeftRight", this, &AmainChar_Fox::moveLeftRight);

	PlayerInputComponent->BindAxis("GoSlow", this, &AmainChar_Fox::GoSlow);
	PlayerInputComponent->BindAxis("crouch", this, &AmainChar_Fox::GoCrouch);

	
	PlayerInputComponent->BindAxis("xAxis", this, &AmainChar_Fox::CameraYaw_z);
	PlayerInputComponent->BindAxis("yAxis", this, &AmainChar_Fox::CameraPitch_y);

	//look around
	PlayerInputComponent->BindAxis("LookAround", this, &AmainChar_Fox::CanLookAround);
	
	 
	//interact
	PlayerInputComponent->BindAction("interact", IE_Pressed, this, &AmainChar_Fox::interact_f);
	//jumping
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AmainChar_Fox::JumpFox);

}



void AmainChar_Fox :: moveForward(float val) {
	if (disableInput_movement) {
		return;
	}

	
	
	const FRotator Rotation = FollowCamera->GetComponentRotation(); //RootComponent->GetComponentRotation();//Controller->GetControlRotation();
	
	const FRotator YawRotation(0.0f, Rotation.Yaw+10, 0.0f);

	

	if (val != 0) {
		if (!bIsMoving) {
			FRotator resetFoxRotation(RootComponent->GetComponentRotation());
			resetFoxRotation.Yaw -= 20;
			//resetFoxRotation.Roll += 20;
			//cameraBoom->SetWorldRotation(resetFoxRotation);
		}
		RootComponent->SetWorldRotation(YawRotation);
		bIsMoving = true;
	}
	else {
		bIsMoving = false;
	}
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	bIsMovingForward = val > 0 ? true : false;

	AddMovementInput(Direction, val);

	/*
	if (val == 1) {
		if (Controller != nullptr) {
			const FRotator Rotation = RootComponent->GetComponentRotation();//Controller->GetControlRotation();
			const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);


			AddMovementInput(Direction, 1);
		}
	}
	else if (val == -1) {
		if (Controller != nullptr) {
			const FRotator Rotation = RootComponent->GetComponentRotation();// Controller->GetControlRotation();
			const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

			AddMovementInput(Direction, -1);
		}
	}
	*/

	
}


void AmainChar_Fox::GoSlow(float val) {
	if (disableInput_movement) {
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("working"));

	
	if (val == 1) {
		bIsWalking = true;
	}
	else {
		bIsWalking = false;
	}
}

void AmainChar_Fox::GoCrouch(float val) {
	if (disableInput_movement) {
		return;
	}

	
	if (val == 1) {
		Crouch();

		bIsCrouching = true;

		if (StandCrouch < 100) {
			StandCrouch += 400 * GetWorld()->DeltaTimeSeconds;
		}
		else {
			StandCrouch = 100;
		}
	}
	else {
		bIsCrouching = false;
		UnCrouch();
		if (StandCrouch > 0) {
			StandCrouch -= 400 * GetWorld()->DeltaTimeSeconds;
		}
		else {
			StandCrouch = 0;
		}
	}
}

void AmainChar_Fox::CameraYaw_z(float val) {
	if (disableInput_camera) {
		return;
	}

	if (!bCanLookAround) {
		//return;
	}
	FRotator newR = FRotator(0, 0, 0);
	newR.Yaw += val;
	cameraBoom->AddRelativeRotation(newR);
	

}

void AmainChar_Fox::CameraPitch_y(float val) {
	if (disableInput_camera) {
		return;
	}

	if (!bCanLookAround) {
		//return;
	}
	FRotator newR = cameraBoom->GetRelativeRotation();
	newR.Pitch = FMath::Clamp(newR.Pitch + val, -80.0f, 4.0f);

	cameraBoom->SetRelativeRotation(newR);
}

void AmainChar_Fox::CanLookAround(float val) {
	if (disableInput_camera) {
		return;
	}

	bCanLookAround = false;
	if (val == 1) {
		bCanLookAround = true;
	}
	else {
		//cameraBoom->SetRelativeRotation(FRotator(-20, -35, 0.f));
	}
}


void AmainChar_Fox::moveLeftRight(float val) {
	if (disableInput_movement) {
		return;
	}

	if (!bIsMovingForward) {
		val *= -1;
	}

	cameraBoom->AddWorldRotation(FRotator(0, val * 50 * GetWorld()->GetDeltaSeconds(), 0));

	/*
	if (val == -1) {
		RootComponent->AddWorldRotation(FRotator(0,-50 * GetWorld()->GetDeltaSeconds(),0));
	}
	else if (val == 1) {
		RootComponent->AddWorldRotation(FRotator(0, 50 * GetWorld()->GetDeltaSeconds(), 0));
	}
	*/
}
 
void AmainChar_Fox::interact_f() {
	//--------return if disabled
	if (disableInput_interact) {
		return;
	}

	UFox_AnimInstance* animInst = Cast<UFox_AnimInstance>(GetMesh()->GetAnimInstance());
	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());

	//to streach=========|============
	if (What_to_do_with_interact == 0) {
		interact += 50;
		if (interact >= 500)
			interact = 500;
	}
	// to eat mushrooom
	else if (What_to_do_with_interact == 1) {
		if (gameInst->bIsCurrentFoodIsThere) {
			animInst->AnimState = 1;
			animInst->inner_AnimState = 1;
			
			const FRotator YawRotation(0.0f, RootComponent->GetComponentRotation().Yaw, 0.0f);
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

			OtherActorLoc_ToSnapLoc -= Direction*100;

			OtherActorLoc_ToSnapLoc.Z = RootComponent->GetComponentLocation().Z;
			RootComponent->SetWorldLocation(OtherActorLoc_ToSnapLoc);


		}

		

	}
}


void AmainChar_Fox :: HudManagement() {
	if (What_to_do_with_interact != 0) {
		
	}
}

void AmainChar_Fox::JumpFox() {
	Jump();
}


void AmainChar_Fox::EnableRagDoll() {
	
	
	if (!bisDead) {
		GetMesh()->SetSimulatePhysics(true);
		cameraBoom->TargetArmLength = 300;
		bisDead = true;
		cameraBoom->SetWorldRotation(FRotator(290, 0, 0));
		DisableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		cameraBoom->bDoCollisionTest = false;
	}

}

