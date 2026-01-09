// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/DemoPlayerCombatComponent.h"
#include "AbilitySystem/DemoAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/DemoGameplayAbility.h"
#include "Item/Weapons/DemoWeaponBase.h"

void UDemoPlayerCombatComponent::GiveToWeaponAbilityToASC(ADemoWeaponBase* InEquipWeapon, UDemoAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
    check(InASCToGive);

    ClearWeaponAbilityFromASC(InASCToGive);

    UE_LOG(LogTemp, Log, TEXT("Giving weapon abilities to ASC from weapon: %s"), *InEquipWeapon->GetName());

    for (const FWeaponAbilitySet& AbilitySet : InEquipWeapon->GetWeaponAbilitySets())
    {
        //if (!AbilitySet.IsValid()) continue;

        if(!AbilitySet.AbilityClass)
        {
            UE_LOG(LogTemp, Warning, TEXT("AbilitySet.AbilityClass is null in weapon: %s"), *InEquipWeapon->GetName());
            continue;
        }

        if(!AbilitySet.InputTag.IsValid())
        {
            UE_LOG(LogTemp, Warning, TEXT("AbilitySet.InputTag is invalid in weapon: %s"), *InEquipWeapon->GetName());
            continue;
        }

        // 어빌리티 부여
        FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityClass);
        AbilitySpec.SourceObject = InASCToGive->GetOwnerActor();
        AbilitySpec.Level = ApplyLevel;
        AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);

        FGameplayAbilitySpecHandle NewHandle = InASCToGive->GiveAbility(AbilitySpec);
        EquippedWeaponAbilityHandles.Add(NewHandle);
    }
}

void UDemoPlayerCombatComponent::ClearWeaponAbilityFromASC(UDemoAbilitySystemComponent* InASCToClear)
{
    check(InASCToClear);
    for(FGameplayAbilitySpecHandle& AbilityHandle : EquippedWeaponAbilityHandles)
    {
        InASCToClear->ClearAbility(AbilityHandle);
    }
    EquippedWeaponAbilityHandles.Empty();
}
