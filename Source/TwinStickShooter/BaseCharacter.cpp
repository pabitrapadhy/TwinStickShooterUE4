#include "BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseCharacter::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABaseCharacter::UpdateHealth(const float Delta)
{
	if (CharacterHealthStatus == ECharacterHealthStatus::Alive)
	{
		Health += Delta;
		UpdateHealthStatus();
	}
	/*Health += Delta;
	UpdateHealthStatus();*/
}

void ABaseCharacter::UpdateHealthStatus()
{
	CharacterHealthStatus = (Health <= 0) ? ECharacterHealthStatus::Dead : ECharacterHealthStatus::Alive;
	/*IsDead = Health <= 0;*/ 
}

#if WITH_EDITOR
void ABaseCharacter::PostEditChangeProperty(FPropertyChangedEvent& Event)
{
	CharacterHealthStatus = ECharacterHealthStatus::Alive;
	/*IsDead = false;*/
	Health = 100;
	
	Super::PostEditChangeProperty(Event);
	UpdateHealthStatus();
}
#endif