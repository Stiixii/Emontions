// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AEmoPlayerController.h"


// Sets default values
AEmoPlayerController::AEmoPlayerController()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEmoPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEmoPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEmoPlayerController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

