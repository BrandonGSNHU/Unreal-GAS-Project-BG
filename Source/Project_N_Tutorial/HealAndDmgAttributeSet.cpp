// Fill out your copyright notice in the Description page of Project Settings.


#include "HealAndDmgAttributeSet.h"
#include "Net/UnrealNetwork.h"

UHealAndDmgAttributeSet::UHealAndDmgAttributeSet()
{
	Heal = 10.0f;
	Damage = 15.0f;
}

void UHealAndDmgAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UHealAndDmgAttributeSet, Heal, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHealAndDmgAttributeSet, Damage, COND_None, REPNOTIFY_Always);
}

