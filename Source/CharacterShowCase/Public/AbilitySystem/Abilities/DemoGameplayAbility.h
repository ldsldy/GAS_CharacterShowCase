// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "DemoGameplayAbility.generated.h"

class UPawnCombatComponent;
class UDemoAbilitySystemComponent;

UENUM(BlueprintType)
enum class EDemoAbilityActivationPolicy : uint8
{
    OnTriggerd,
    OnGiven
};

/**
 *  게임플레이 어빌리티에 도움을 주는 헬퍼 함수를 제공하는 기본 어빌리티 클래스
 */
UCLASS()
class CHARACTERSHOWCASE_API UDemoGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
    virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
    virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

    UFUNCTION(BlueprintPure, Category = "DemoAbility")
    UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

    UFUNCTION(BlueprintPure, Category = "DemoAbility")
    UDemoAbilitySystemComponent* GetDemoAbilitySystemComponentFromActorInfo() const;
    
protected:
    UPROPERTY(EditDefaultsOnly, Category = "DemoAbility")
    EDemoAbilityActivationPolicy AbilityActivationPolicy = EDemoAbilityActivationPolicy::OnTriggerd;
};
