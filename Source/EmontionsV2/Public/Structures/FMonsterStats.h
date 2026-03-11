#pragma once

#include "CoreMinimal.h"
#include "FMonsterStats.generated.h"

USTRUCT(BlueprintType)
struct FMonsterStats
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 HP = 50;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 ATK = 50;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 DEF = 50;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 SPATK = 50;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 SPDEF = 50;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 SPD = 50;
};

