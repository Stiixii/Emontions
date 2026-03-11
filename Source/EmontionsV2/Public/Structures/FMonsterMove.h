#pragma once

#include "Enums/ElementalType.h"
#include "Enums/EmotionType.h"
#include "Enums/MoveCategory.h"
#include "CoreMinimal.h"
#include "FMonsterPrefixMove.h"
#include "FMonsterSuffixMove.h"
#include "FMonsterMove.generated.h"

USTRUCT(BlueprintType)
struct FMonsterMove
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FName FullName = NAME_None;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FMonsterPrefixMove PrefixMove;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FMonsterSuffixMove SuffixMove;

};
