// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "GameplayAbilitySpec.h"
#include "DemoPlayerCombatComponent.generated.h"

class UDemoAbilitySystemComponent;
class ADemoWeaponBase;
/**
 * 
 */
UCLASS()
class CHARACTERSHOWCASE_API UDemoPlayerCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()
	
public:
    // 어빌리티 연결
    UFUNCTION(BlueprintCallable, Category = "Demo|Combat")
    void GiveToWeaponAbilityToASC(ADemoWeaponBase* InEquipWeapon, UDemoAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

    UFUNCTION(BlueprintCallable, Category = "Demo|Combat")
    void ClearWeaponAbilityFromASC(UDemoAbilitySystemComponent* InASCToClear);

private:
    UPROPERTY()
    TArray<FGameplayAbilitySpecHandle> EquippedWeaponAbilityHandles;
};
