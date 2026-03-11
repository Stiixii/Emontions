// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster/Moves/EmoMonsterMove.h"

UEmoMonsterMove::UEmoMonsterMove(const FMonsterPrefixMove& Prefix, const FMonsterSuffixMove& Suffix)
{
	FullName = FName(*(Prefix.Name.ToString() + Suffix.Name.ToString()));
	PrefixMove = Prefix;
	SuffixMove = Suffix;
}
