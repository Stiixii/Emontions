#pragma once

#include "Enums/ElementalType.h"
#include "Enums/MoveCategory.h"
#include "CoreMinimal.h"
#include "FMonsterPrefixMove.generated.h"

USTRUCT(BlueprintType)
struct FMonsterPrefixMove
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FName Name = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EElementalType ElementType = EElementalType::None;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 BasePower = 60;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EMoveCategory Category = EMoveCategory::Special;
};
