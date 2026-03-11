// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperZDCharacter.h"
#include "AEmoBaseController.generated.h"

UCLASS()
class EMONTIONSV2_API AEmoBaseCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEmoBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
