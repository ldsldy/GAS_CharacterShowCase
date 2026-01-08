// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/DemoGameplayAbility.h"
#include "DemoPlayerGameplayAbility.generated.h"

class ADemoPlayerCharacter;
class ADemoPlayerController;
class UDemoPlayerCombatComponent;

/**
 *   플레이어 전용 어빌리티를 위한 헬퍼 함수를 제공하는 기본 어빌리티 클래스
 */
UCLASS()
class CHARACTERSHOWCASE_API UDemoPlayerGameplayAbility : public UDemoGameplayAbility
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintPure, Category = "DemoAbility")
    ADemoPlayerCharacter* GetDemoPlayerCharacterFromActorInfo();
    
    UFUNCTION(BlueprintPure, Category = "DemoAbility")
    ADemoPlayerController* GetDemoPlayerControllerFromActorInfo();
    
    UFUNCTION(BlueprintPure, Category = "DemoAbility")
    UDemoPlayerCombatComponent* GetDemoPlayerCombatComponentFromActorInfo();

private:
    TWeakObjectPtr<ADemoPlayerCharacter> CachedDemoPlayerCharacter;
    TWeakObjectPtr<ADemoPlayerController> CachedDemoPlayerController;
};
