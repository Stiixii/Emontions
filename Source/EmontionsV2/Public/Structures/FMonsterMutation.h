#pragma once

#include "FMonsterMove.h"
#include "FMonsterStats.h"
#include "Enums/EmotionType.h"
#include "Enums/ElementalType.h"
#include "Enums/MutationSlot.h"
#include "CoreMinimal.h"
#include "FMonsterMutation.generated.h"

USTRUCT(BlueprintType)
struct FMonsterMutation
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EMutationSlot Slot = EMutationSlot::None;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EElementalType MutatedElementType = EElementalType::None;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EEmotionType MutatedEmotionType = EEmotionType::None;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FMonsterStats StatModifiers;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FMonsterMove> OverrideMoves;
};