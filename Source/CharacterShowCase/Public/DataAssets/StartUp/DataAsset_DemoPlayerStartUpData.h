// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUp/DataAsset_StartUpDataBase.h"
#include "GameplayTagContainer.h"
#include "DataAsset_DemoPlayerStartUpData.generated.h"

USTRUCT(BlueprintType)
struct FDemoPlayerAbilitySet
{
    GENERATED_BODY()

public:
    // 어빌리티에 연결된 입력 태그
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
    FGameplayTag InputTag;

    // 부여할 어빌리티 클래스
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TSubclassOf<UDemoGameplayAbility> AbilityToGrant;

    // 유효한지 여부 반환
    bool IsValid() const;
};

/**
 * 
 */
UCLASS()
class CHARACTERSHOWCASE_API UDataAsset_DemoPlayerStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()
	
public:
    virtual void GiveToAbilitySystemComponent(UDemoAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

private:
    // 어빌리티 태그와 어빌리티 클래스 구조체 목록
    UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty="InputTag"))
    TArray<FDemoPlayerAbilitySet> PlayerAbilitySets;
};
