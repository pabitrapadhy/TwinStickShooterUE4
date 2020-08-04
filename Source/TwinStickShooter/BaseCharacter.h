// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UENUM(BlueprintType)
enum class ECharacterHealthStatus : uint8
{
	Alive	UMETA(DisplayName="Alive"),
    Dead	UMETA(DisplayName="Dead")
};

UCLASS(Blueprintable)
class TWINSTICKSHOOTER_API ABaseCharacter : public ACharacter
{
public:
	// properties
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="BaseCharacter")
	int Health = 100;

	/*UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="BaseCharacter")
	bool IsDead = false;*/
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="BaseCharacter")
	ECharacterHealthStatus CharacterHealthStatus = ECharacterHealthStatus::Alive;

	// functions
	UFUNCTION(BlueprintCallable, Category="BaseCharacter")
    virtual void UpdateHealth(float Delta);

	virtual void UpdateHealthStatus();

	#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& Event) override;
#endif

public:
	GENERATED_BODY()
	ABaseCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
