// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "WeaponDataStruct.generated.h"


// 무기 능력 세트 구조체
USTRUCT(BlueprintType)
struct FWeaponAbilitySet
{
    GENERATED_BODY()

public:
    // 인풋 태그
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "InputTag")
    FGameplayTag InputTag;

    // 능력 클래스
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AbilityClass")
    TSubclassOf<class UDemoGameplayAbility> AbilityClass;
};
/**
 * 
 */

USTRUCT(BlueprintType)
struct FWeaponData
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
    FGameplayTag WeaponTag;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
    TSubclassOf<class UAnimInstance> WeaponAnimClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
    TArray<FWeaponAbilitySet> AbilitySets;
};