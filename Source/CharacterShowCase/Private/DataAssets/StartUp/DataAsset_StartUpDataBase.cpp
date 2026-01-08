// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUp/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/DemoAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/DemoGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UDemoAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
    check(InASCToGive);

    GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
    GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UDemoGameplayAbility>>& InAbilitiesToGive, UDemoAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
    if (InAbilitiesToGive.IsEmpty()) return;

    for (const TSubclassOf<UDemoGameplayAbility>& Ability : InAbilitiesToGive)
    {
        if (!Ability) continue;

        // 어빌리티 부여
        FGameplayAbilitySpec AbilitySpec(Ability);
        AbilitySpec.SourceObject = InASCToGive->GetOwnerActor();
        AbilitySpec.Level = ApplyLevel;

        InASCToGive->GiveAbility(AbilitySpec);
    }
}
