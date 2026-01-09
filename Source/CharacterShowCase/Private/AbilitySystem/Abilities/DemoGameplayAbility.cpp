// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/DemoGameplayAbility.h"
#include "AbilitySystem/DemoAbilitySystemComponent.h"
#include "Components/Combat/PawnCombatComponent.h"


UDemoGameplayAbility::UDemoGameplayAbility()
{
    InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UDemoGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
    Super::OnGiveAbility(ActorInfo, Spec);

    // 자동 활성화 정책인 경우 어빌리티를 즉시 활성화합니다.
    if(AbilityActivationPolicy == EDemoAbilityActivationPolicy::OnGiven)
    {
        if (ActorInfo && !Spec.IsActive())
        {
            ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
        }
    }
}

void UDemoGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
    Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

    if(AbilityActivationPolicy == EDemoAbilityActivationPolicy::OnGiven)
    {
        if (ActorInfo)
        {
            ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
        }
    }
}

UPawnCombatComponent* UDemoGameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
    return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}

UDemoAbilitySystemComponent* UDemoGameplayAbility::GetDemoAbilitySystemComponentFromActorInfo() const
{
    return Cast<UDemoAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}
