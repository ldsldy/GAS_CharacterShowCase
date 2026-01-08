// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

// 플레이어 인풋 태그와 인풋 액션을 묶는 구조체
USTRUCT(BlueprintType)
struct FDemoPlayerInputActionConfig
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
    FGameplayTag InputTag;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TObjectPtr<UInputAction> InputAction;

    // 유효성 검사 헬퍼 함수
    bool IsValid() const
    {
        return InputTag.IsValid() && InputAction;
    }
};

/**
 * 
 */
UCLASS()
class CHARACTERSHOWCASE_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TObjectPtr<UInputMappingContext> DefaultMappingContext;

    // 일반 입력 구조체 배열
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
    TArray<FDemoPlayerInputActionConfig> NativeInputActions;

    // 태그로 네이티브 인풋 액션 찾기
    UInputAction* FindNativeInputActionByTag(const FGameplayTag& InTag) const;

    // 어빌리티 입력 구조체 배열
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
    TArray<FDemoPlayerInputActionConfig> AbilityInputActions;
};
