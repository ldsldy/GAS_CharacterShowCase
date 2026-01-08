// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "DemoCharacterBase.generated.h"

class UDemoAbilitySystemComponent;
class UDemoAttributeSet;
class UDataAsset_StartUpDataBase;

/**
 *  캐릭터들의 기본 베이스 클래스, 어빌리티 시스템 부착
 */
UCLASS()
class CHARACTERSHOWCASE_API ADemoCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ADemoCharacterBase();

    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

    FORCEINLINE UDemoAbilitySystemComponent* GetDemoAbilitySystemComponent() const { return DemoAbilitySystemComponent; }
    FORCEINLINE UDemoAttributeSet* GetDemoAttributeSet() const { return DemoAttributeSet; }

protected:
    virtual void PossessedBy(AController* NewController) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
    TObjectPtr<UDemoAbilitySystemComponent> DemoAbilitySystemComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
    TObjectPtr<UDemoAttributeSet> DemoAttributeSet;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterData")
    TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilitySystem")
    EGameplayEffectReplicationMode AscReplicationMode = EGameplayEffectReplicationMode::Mixed;
};
