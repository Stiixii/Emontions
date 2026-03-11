// EmoPlayerAnimInstance.h
#pragma once

#include "CoreMinimal.h"
#include "PaperZDAnimInstance.h"
#include "EmoPlayerAnimInstance.generated.h"

UCLASS()
class EMONTIONSV2_API UEmoPlayerAnimInstance : public UPaperZDAnimInstance
{
	GENERATED_BODY()

public:
	virtual void OnInit_Implementation() override;
	virtual void OnTick_Implementation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	float DirectionX;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	float DirectionY;
};