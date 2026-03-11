#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Enums/ElementalType.h"
#include "Enums/EmotionType.h"
#include "Structures/FMonsterMutation.h"
#include "Structures/FMonsterStats.h"
#include "EmoDexMonster.generated.h"

UCLASS(BlueprintType)
class UDexMonster : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Identity")
	FName ID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Identity")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Identity")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Typing")
	EElementalType ElementType = EElementalType::None;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Typing")
	EEmotionType EmotionType = EEmotionType::None;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	FMonsterStats BaseStats;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moves")
	TArray<FMonsterMove> PotentialMoves;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mutation")
	FMonsterMutation Mutation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Misc")
	int32 CaptureRate = 45;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Visuals")
	TSoftObjectPtr<UTexture2D> FrontSprite;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Visuals")
	TSoftObjectPtr<UTexture2D> BackSprite;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Visuals")
	TSoftObjectPtr<UTexture2D> IconSprite;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("DexMonster", GetFName());
	}
};