// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/DemoPlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h" 
#include "EnhancedInputSubsystems.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/Input/PlayerInputComponent.h"
#include "DemoPlayerGameplayTag.h"
#include "AbilitySystem/DemoAbilitySystemComponent.h"
#include "AbilitySystem/DemoAttributeSet.h"
#include "DataAssets/StartUp/DataAsset_DemoPlayerStartUpData.h"
#include "Components/Combat/DemoPlayerCombatComponent.h"

ADemoPlayerCharacter::ADemoPlayerCharacter()
{
    GetCapsuleComponent()->InitCapsuleSize(35.f, 90.f);

    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(GetRootComponent());
    CameraBoom->TargetArmLength = 200.f;
    CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
    CameraBoom->bUsePawnControlRotation = true;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
    GetCharacterMovement()->MaxWalkSpeed = 500.f;
    GetCharacterMovement()->AirControl = 0.35f;
    GetCharacterMovement()->JumpZVelocity = 500.f;
    GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
    GetCharacterMovement()->BrakingDecelerationFalling = 1500.f;

    DemoPlayerCombatComponent = CreateDefaultSubobject<UDemoPlayerCombatComponent>(TEXT("DemoPlayerCombatComponent"));
}

void ADemoPlayerCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    if (!CharacterStartUpData.IsNull())
    {
        if(UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.LoadSynchronous())
        {
            // 이 캐릭터의 어빌리티 시스템 컴포넌트에 스타트업 데이터의 어빌리티 부여
            LoadedData->GiveToAbilitySystemComponent(DemoAbilitySystemComponent);
        }
    }
}

void ADemoPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    checkf(InputConfigDataAsset, TEXT("InputConfigDataAsset is nullptr in %s"), *GetName());

    // 로컬 플레이어의 입력 서브시스템에 매핑 컨텍스트 추가
    ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
    check(Subsystem);
    Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

    // 유효한 인력 컴포넌트를 가지고 있는지 확인
    UPlayerInputComponent* DemoPlayerInputComponent = CastChecked<UPlayerInputComponent>(PlayerInputComponent);

    // InputConfigDataAsset에 정의된 입력 액션을 함수에 바인딩
    DemoPlayerInputComponent->BindNativeInputAction(InputConfigDataAsset, DemoPlayerGameplayTag::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
    DemoPlayerInputComponent->BindNativeInputAction(InputConfigDataAsset, DemoPlayerGameplayTag::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);

    // 스킬1,2,3,4와 대시 입력 액션을 바인딩
    // 초기에는 UDataAsset_StartUpDataBase에서 부여한 어빌리티와 연동(GameplayTag InputTag로 연결)
    DemoPlayerInputComponent->BindAbilityInputAction(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed, &ThisClass::Input_AbilityInputReleased);
}

void ADemoPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ADemoPlayerCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
    const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
    const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

    if (MovementVector.Y != 0.f)
    {
        const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);

        AddMovementInput(ForwardDirection, MovementVector.Y);
    }

    if (MovementVector.X != 0.f)
    {
        const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
        AddMovementInput(RightDirection, MovementVector.X);
    }
}

void ADemoPlayerCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
    const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

    if (LookAxisVector.X != 0.f)
    {
        AddControllerYawInput(LookAxisVector.X);
    }

    if (LookAxisVector.Y != 0.f)
    {
        AddControllerPitchInput(LookAxisVector.Y);
    }
}

void ADemoPlayerCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
    DemoAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
}

void ADemoPlayerCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
    DemoAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}
