// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/DemoCharacterBase.h"
#include "GameplayTagContainer.h"
#include "DemoPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UDataAsset_InputConfig;
class UDemoPlayerCombatComponent;
struct FInputActionValue;

/**
 *   블루프린트에서 어빌리티를 사용함에 있어서 도움을 주는 헬퍼 함수들을 포함한 클래스
 */
UCLASS()
class CHARACTERSHOWCASE_API ADemoPlayerCharacter : public ADemoCharacterBase
{
	GENERATED_BODY()

public:
    ADemoPlayerCharacter();

    FORCEINLINE UDemoPlayerCombatComponent* GetDemoCommatComponent() const { return DemoPlayerCombatComponent; }
protected:
    virtual void PossessedBy(AController* NewController) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    virtual void BeginPlay() override;

private:
#pragma region Components
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<USpringArmComponent> CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UCameraComponent> FollowCamera;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UDemoPlayerCombatComponent> DemoPlayerCombatComponent;

#pragma endregion

#pragma region Inputs
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UDataAsset_InputConfig> InputConfigDataAsset;

    void Input_Move(const FInputActionValue& InputActionValue);
    void Input_Look(const FInputActionValue& InputActionValue);

    void Input_AbilityInputPressed(FGameplayTag InInputTag);
    void Input_AbilityInputReleased(FGameplayTag InInputTag);
#pragma endregion
};
