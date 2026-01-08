// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "DemoAbilitySystemComponent.generated.h"

/**
 *  어빌리티를 태그로 찾아서 활성화 시키는 기능
 */
UCLASS()
class CHARACTERSHOWCASE_API UDemoAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
    void OnAbilityInputPressed(const FGameplayTag& InInputTag);
    void OnAbilityInputReleased(const FGameplayTag& InInputTag);
};
