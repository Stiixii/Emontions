#pragma once
#include "Structures/FMonsterSuffixMove.h"
#include "EmoMonsterPrefixMoveDataAsset.generated.h"

UCLASS()
class EMONTIONSV2_API UEmoMonsterPrefixMoveDataAsset : public UPrimaryDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName Name = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EElementalType ElementType = EElementalType::None;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 BasePower = 60;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EMoveCategory Category = EMoveCategory::Special;
	
	virtual FPrimaryAssetId GetPrimaryAssetId() const override { return FPrimaryAssetId("AssetItems", GetFName()); } 
};