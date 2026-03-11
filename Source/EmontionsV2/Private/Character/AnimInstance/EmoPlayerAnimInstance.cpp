#include "Character/AnimInstance/EmoPlayerAnimInstance.h"

#include "Kismet/KismetSystemLibrary.h"

void UEmoPlayerAnimInstance::OnInit_Implementation()
{
	Super::OnInit_Implementation();
}

void UEmoPlayerAnimInstance::OnTick_Implementation(float DeltaTime)
{
	Super::OnTick_Implementation(DeltaTime);

	AActor* Owner = GetOwningActor();
	if (Owner)
	{
		FVector Velocity = Owner->GetVelocity();
        
		if (!Velocity.IsNearlyZero())
		{
			DirectionX = Velocity.X;
			DirectionY = Velocity.Y * -1.0f;
		}
	}
}