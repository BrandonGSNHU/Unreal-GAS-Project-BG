// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "HealAndDmgAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_N_TUTORIAL_API UHealAndDmgAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UHealAndDmgAttributeSet();

	// Heal Attribute
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing=OnRep_Heal)
	FGameplayAttributeData Heal;
	ATTRIBUTE_ACCESSORS_BASIC(UHealAndDmgAttributeSet, Heal)

	// Damage Attribute
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing=OnRep_Damage)
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS_BASIC(UHealAndDmgAttributeSet, Damage)

public:
	UFUNCTION()
	void OnRep_Heal(const FGameplayAttributeData& OldValue)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UHealAndDmgAttributeSet, Heal, OldValue);
	}

	UFUNCTION()
	void OnRep_Damage(const FGameplayAttributeData& OldValue)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UHealAndDmgAttributeSet, Damage, OldValue);
	}

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
