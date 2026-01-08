// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/DemoPlayerGameplayAbility.h"
#include "Characters/DemoPlayerCharacter.h"
#include "Controllers/DemoPlayerController.h"
#include "Components/Combat/DemoPlayerCombatComponent.h"

ADemoPlayerCharacter* UDemoPlayerGameplayAbility::GetDemoPlayerCharacterFromActorInfo()
{
    if (!CachedDemoPlayerCharacter.IsValid())
    {
        CachedDemoPlayerCharacter = Cast<ADemoPlayerCharacter>(CurrentActorInfo->AvatarActor);
    }
    return CachedDemoPlayerCharacter.IsValid() ? CachedDemoPlayerCharacter.Get() : nullptr;
}

ADemoPlayerController* UDemoPlayerGameplayAbility::GetDemoPlayerControllerFromActorInfo()
{
    if (!CachedDemoPlayerController.IsValid())
    {
        CachedDemoPlayerController = Cast<ADemoPlayerController>(CurrentActorInfo->PlayerController);
    }
    return CachedDemoPlayerController.IsValid() ? CachedDemoPlayerController.Get() : nullptr;
}

UDemoPlayerCombatComponent* UDemoPlayerGameplayAbility::GetDemoPlayerCombatComponentFromActorInfo()
{
    return GetDemoPlayerCharacterFromActorInfo()->GetDemoCommatComponent();
}