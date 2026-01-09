// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUp/DataAsset_DemoPlayerStartUpData.h"
#include "AbilitySystem/Abilities/DemoGameplayAbility.h"
#include "AbilitySystem/DemoAbilitySystemComponent.h"

bool FDemoPlayerAbilitySet::IsValid() const
{
    return InputTag.IsValid() && AbilityToGrant;
}

void UDataAsset_DemoPlayerStartUpData::GiveToAbilitySystemComponent(UDemoAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
    Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

    //플레이어 어빌리티 세트 부여
    for (const FDemoPlayerAbilitySet& AbilitySet : PlayerAbilitySets)
    {
        if(!AbilitySet.IsValid()) continue;

        FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
        AbilitySpec.SourceObject = InASCToGive->GetOwnerActor();
        AbilitySpec.Level = ApplyLevel;
        AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);

        InASCToGive->GiveAbility(AbilitySpec);
    }
}
