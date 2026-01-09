// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponDataStruct.h"
#include "DemoWeaponBase.generated.h"

UCLASS()
class CHARACTERSHOWCASE_API ADemoWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADemoWeaponBase();

    UFUNCTION(BlueprintCallable, Category = "Weapon|Data")
    const FWeaponData& GetWeaponData() const { return WeaponData; }

    UFUNCTION(BlueprintCallable, Category = "Weapon|Data")
    const TArray<FWeaponAbilitySet>& GetWeaponAbilitySets() const { return WeaponData.AbilitySets; }

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
    TObjectPtr<UStaticMeshComponent> WeaponMesh;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|Data")
    FWeaponData WeaponData;
};
