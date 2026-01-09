// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Weapons/DemoWeaponBase.h"
#include "AbilitySystem/Abilities/DemoGameplayAbility.h"

// Sets default values
ADemoWeaponBase::ADemoWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

    WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
    RootComponent = WeaponMesh;
}



