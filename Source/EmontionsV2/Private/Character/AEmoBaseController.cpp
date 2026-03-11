// Fill out your copyright notice in the Description page of Project Settings.


#include "EmontionsV2/Public/Character/AEmoBaseController.h"


// Sets default values
AEmoBaseCharacter::AEmoBaseCharacter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEmoBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEmoBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

