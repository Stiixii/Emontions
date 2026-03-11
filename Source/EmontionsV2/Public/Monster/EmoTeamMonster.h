#pragma once

#include "CoreMinimal.h"
#include "EmoDexMonster.h"
#include "Enums/ElementalType.h"
#include "Enums/EmotionType.h"
#include "Structures/FMonsterMutation.h"
#include "Structures/FMonsterStats.h"
#include "Structures/FMonsterStatus.h"
#include "UObject/Object.h"
#include "EmoTeamMonster.generated.h"

UCLASS(BlueprintType)
class UEmoTeamMonster : public UObject
{
    GENERATED_BODY()

public:

    // Identité
    UPROPERTY(BlueprintReadOnly, Category = "Identity")
    FName ID = NAME_None;
    UPROPERTY(BlueprintReadOnly, Category = "Identity")
    FText Name;
    UPROPERTY(BlueprintReadWrite, Category = "Identity")
    FText Nickname;
    UPROPERTY(BlueprintReadOnly, Category = "Identity")
    FText Description;

    // Typage
    UPROPERTY(BlueprintReadOnly, Category = "Typing")
    EElementalType ElementType = EElementalType::None;
    UPROPERTY(BlueprintReadOnly, Category = "Typing")
    EEmotionType EmotionType = EEmotionType::None;

    // Mutation
    UPROPERTY(BlueprintReadOnly, Category = "Mutation")
    FMonsterMutation Mutation;
    UPROPERTY(BlueprintReadWrite, Category = "Mutation")
    bool bIsMutated = false;
    UPROPERTY(BlueprintReadWrite, Category = "Mutation")
    bool bMutationUnlocked = false;

    // Stats de base
    UPROPERTY(BlueprintReadOnly, Category = "Stats")
    FMonsterStats BaseStats;

    // Stats calculées au niveau actuel
    UPROPERTY(BlueprintReadOnly, Category = "Stats")
    int32 MaxHP = 0;
    UPROPERTY(BlueprintReadOnly, Category = "Stats")
    int32 ATK = 0;
    UPROPERTY(BlueprintReadOnly, Category = "Stats")
    int32 DEF = 0;
    UPROPERTY(BlueprintReadOnly, Category = "Stats")
    int32 SPATK = 0;
    UPROPERTY(BlueprintReadOnly, Category = "Stats")
    int32 SPDEF = 0;
    UPROPERTY(BlueprintReadOnly, Category = "Stats")
    int32 SPD = 0;

    // Progression
    UPROPERTY(BlueprintReadOnly, Category = "Progression")
    int32 Level = 1;
    UPROPERTY(BlueprintReadOnly, Category = "Progression")
    int32 Experience = 0;

    // Moves
    UPROPERTY(BlueprintReadWrite, Category = "Moves")
    TArray<FMonsterMove> EquippedMoves;    // max 4
    UPROPERTY(BlueprintReadOnly, Category = "Moves")
    TArray<FMonsterMove> LearnedMoves;

    // État courant
    UPROPERTY(BlueprintReadWrite, Category = "State")
    int32 CurrentHP = 0;
    UPROPERTY(BlueprintReadWrite, Category = "State")
    FMonsterStatus CurrentStatus;

    // ── Factory ─────────────────────────────────

    UFUNCTION(BlueprintCallable, Category = "Monster", meta = (WorldContext = "Outer"))
    static UEmoTeamMonster* CreateFromDex(UObject* Outer, const UDexMonster* Dex, int32 InLevel)
    {
        if (!Dex) return nullptr;

        UEmoTeamMonster* M  = NewObject<UEmoTeamMonster>(Outer);
        M->ID            = Dex->ID;
        M->Name          = Dex->Name;
        M->Description   = Dex->Description;
        M->ElementType   = Dex->ElementType;
        M->EmotionType   = Dex->EmotionType;
        M->Mutation      = Dex->Mutation;
        M->BaseStats     = Dex->BaseStats;
        M->Level         = FMath::Clamp(InLevel, 1, 100);
        M->ComputeStats();
        M->CurrentHP     = M->MaxHP;
        return M;
    }

    // ── Helpers ──────────────────────────────────

    UFUNCTION(BlueprintCallable, Category = "Monster")
    FText GetDisplayName() const
    {
        return Nickname.IsEmpty() ? Name : Nickname;
    }

    UFUNCTION(BlueprintCallable, Category = "Monster")
    bool IsAlive() const { return CurrentHP > 0; }

    UFUNCTION(BlueprintCallable, Category = "Monster")
    float GetHPRatio() const
    {
        if (MaxHP <= 0) return 0.f;
        return (float)CurrentHP / (float)MaxHP;
    }

    UFUNCTION(BlueprintCallable, Category = "Monster")
    EElementalType GetEffectiveElementaltType() const
    {
        if (bIsMutated && Mutation.Slot == EMutationSlot::Elemental)
            return Mutation.MutatedElementType;
        return ElementType;
    }

    UFUNCTION(BlueprintCallable, Category = "Monster")
    EEmotionType GetEffectiveEmotionType() const
    {
        if (bIsMutated && Mutation.Slot == EMutationSlot::Emotional)
            return Mutation.MutatedEmotionType;
        return EmotionType;
    }

    UFUNCTION(BlueprintCallable, Category = "Monster")
    void ComputeStats()
    {
        FMonsterStats B = BaseStats;
        MaxHP  = FMath::FloorToInt((2.f * B.HP    * Level) / 100.f) + Level + 10;
        ATK    = FMath::FloorToInt((2.f * B.ATK   * Level) / 100.f) + 5;
        DEF    = FMath::FloorToInt((2.f * B.DEF   * Level) / 100.f) + 5;
        SPATK  = FMath::FloorToInt((2.f * B.SPATK * Level) / 100.f) + 5;
        SPDEF  = FMath::FloorToInt((2.f * B.SPDEF * Level) / 100.f) + 5;
        SPD    = FMath::FloorToInt((2.f * B.SPD   * Level) / 100.f) + 5;
    }
};