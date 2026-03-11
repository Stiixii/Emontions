// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Structures/FMonsterPrefixMove.h"
#include "Structures/FMonsterSuffixMove.h"
#include "UObject/Object.h"
#include "EmoMonsterMove.generated.h"

/**
 * 
 */
UCLASS()
class EMONTIONSV2_API UEmoMonsterMove : public UObject
{
	GENERATED_BODY()

public:
	UEmoMonsterMove() = default;
	UEmoMonsterMove(const FMonsterPrefixMove& Prefix, const FMonsterSuffixMove& Suffix);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName FullName = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FMonsterPrefixMove PrefixMove;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FMonsterSuffixMove SuffixMove;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 BasePower = 60;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EMoveCategory Category = EMoveCategory::Special;
};
