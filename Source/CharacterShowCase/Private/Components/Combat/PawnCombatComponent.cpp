// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"

void UPawnCombatComponent::SetCharacterEquippedWeaponData(UDataAsset_WeaponData* NewEquippedWeaponData)
{
    if (!NewEquippedWeaponData) return;

    if(NewEquippedWeaponData == EquippedWeaponData.Get()) return;

    EquippedWeaponData = NewEquippedWeaponData;
}

ADemoWeaponBase* UPawnCombatComponent::GetCharacterEquippedWeapon() const
{
    if (!EquippedWeaponData.IsValid())
    {
        return nullptr;
    }
    return EquippedWeaponData.Get()->WeaponActorClass;
}
