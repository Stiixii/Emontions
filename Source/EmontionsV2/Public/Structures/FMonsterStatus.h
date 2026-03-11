#pragma once
#include "Enums/StatusEffect.h"
#include "CoreMinimal.h"
#include "FMonsterStatus.generated.h"

USTRUCT(BlueprintType)
struct FMonsterStatus
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EStatusEffect Effect = EStatusEffect::None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Duration = -1;
};
