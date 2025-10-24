// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicAttributeSet.h"
#include "HealAndDmgAttributeSet.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "N_Character_Base.generated.h"


UCLASS()
class PROJECT_N_TUTORIAL_API AN_Character_Base : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AN_Character_Base();

	// Ability System Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	class UBasicAttributeSet* BasicAttributeSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UHealAndDmgAttributeSet* HealAndDmgAttributeSet;


protected:
	// We want this to be BlueprintReadWrite so we can edit it from the blueprint itself
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilitySystem")
	EGameplayEffectReplicationMode ASCReplicationMode = EGameplayEffectReplicationMode::Mixed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// This is for the enemy when it is possessed by the AIController
	virtual void PossessedBy(AController* NewController) override;
	// This is when the player stat is replicated to the client
	virtual void OnRep_PlayerState() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Class is no longer needed in this line since we included the AbilitySystemComponent.h
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

};
