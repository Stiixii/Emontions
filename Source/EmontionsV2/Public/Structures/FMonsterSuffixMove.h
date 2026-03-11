#pragma once

#include "Enums/ElementalType.h"
#include "Enums/EmotionType.h"
#include "Enums/MoveCategory.h"
#include "CoreMinimal.h"
#include "FMonsterSuffixMove.generated.h"

USTRUCT(BlueprintType)
struct FMonsterSuffixMove
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FName Name = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EEmotionType EmotionType = EEmotionType::None;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 BasePower = 60;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EMoveCategory Category = EMoveCategory::Special;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 Accuracy = 100;
};
