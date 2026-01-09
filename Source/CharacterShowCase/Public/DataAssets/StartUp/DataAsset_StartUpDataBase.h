// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UDemoAbilitySystemComponent;
class UDemoGameplayAbility;
/**
 *  시작시에 어빌리티를 어빌리티 컴포넌트에 부여하는 데이터 에셋의 기본 클래스
 */
UCLASS()
class CHARACTERSHOWCASE_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
    virtual void GiveToAbilitySystemComponent(UDemoAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
    // 어빌리티 시스템 컴포넌트에 어빌리티를 부여하는 내부 함수
    void GrantAbilities(const TArray<TSubclassOf<UDemoGameplayAbility>>& InAbilitiesToGive, UDemoAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
    // 시작 시 바로 활성화할 어빌리티 목록
    UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
    TArray<TSubclassOf<UDemoGameplayAbility>> ActivateOnGivenAbilities;

    // 부여만 할 어빌리티 목록
    UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
    TArray<TSubclassOf<UDemoGameplayAbility>> ReactiveAbilities;
};
