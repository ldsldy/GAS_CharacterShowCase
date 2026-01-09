// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DataAsset_WeaponData.generated.h"

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
UCLASS()
class CHARACTERSHOWCASE_API UDataAsset_WeaponData : public UDataAsset
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    FGameplayTag WeaponTag;

    // 무기 액터 클래스
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponActor")
    TSubclassOf<class ADemoWeaponBase> WeaponActorClass;

    // 무기 능력 세트
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponAbility")
    TArray<FWeaponAbilitySet> WeaponAbilitySets;
    
    // 애님 클래스
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
    TSubclassOf<class UAnimInstance> WeaponAnimClass;
};
