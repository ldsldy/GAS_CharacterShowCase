// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "DataAssets/Weapon/DataAsset_WeaponData.h"
#include "PawnCombatComponent.generated.h"

class ADemoWeaponBase;
/**
 * 
 */
UCLASS()
class CHARACTERSHOWCASE_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category = "Demo|Combat")
    void SetCharacterEquippedWeaponData(UDataAsset_WeaponData* NewEquippedWeaponData);

    UFUNCTION(BlueprintCallable, Category = "Demo|Combat")
    ADemoWeaponBase* GetCharacterEquippedWeapon() const;

private:
    TSoftObjectPtr<UDataAsset_WeaponData> EquippedWeaponData;
};
