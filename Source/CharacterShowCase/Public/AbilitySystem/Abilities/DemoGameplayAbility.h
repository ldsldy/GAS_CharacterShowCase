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
    OnTriggerd,    // 어빌리티가 트리거될 때 활성화
    OnGiven        // 어빌리티가 부여될 때 즉시 활성화
}; 

/**
 *  어빌리티의 활성화 정책과 활성화 방식을 정의하는 클래스
 *  게임플레이 어빌리티에 도움을 주는 헬퍼 함수를 제공하는 기본 어빌리티 클래스
 */
UCLASS()
class CHARACTERSHOWCASE_API UDemoGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
    UDemoGameplayAbility();

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
