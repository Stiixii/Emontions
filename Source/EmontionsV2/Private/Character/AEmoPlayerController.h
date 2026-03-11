// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AEmoBaseController.h"
#include "AEmoPlayerController.generated.h"

UCLASS()
class EMONTIONSV2_API AEmoPlayerController : public AEmoBaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEmoPlayerController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
