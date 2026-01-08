// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/DemoCharacterBase.h"
#include "AbilitySystem/DemoAttributeSet.h"
#include "AbilitySystem/DemoAbilitySystemComponent.h"

ADemoCharacterBase::ADemoCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
    PrimaryActorTick.bStartWithTickEnabled = false;

    GetMesh()->SetReceivesDecals(false);

    DemoAbilitySystemComponent = CreateDefaultSubobject<UDemoAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    DemoAbilitySystemComponent->SetIsReplicated(true);
    DemoAbilitySystemComponent->SetReplicationMode(AscReplicationMode);
    
    DemoAttributeSet = CreateDefaultSubobject<UDemoAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* ADemoCharacterBase::GetAbilitySystemComponent() const
{
    return GetDemoAbilitySystemComponent();
}

void ADemoCharacterBase::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    if (DemoAbilitySystemComponent)
    {
        DemoAbilitySystemComponent->InitAbilityActorInfo(this, this);

        ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("CharacterStartUpData is Null : %s"), *GetName());
    }
}
