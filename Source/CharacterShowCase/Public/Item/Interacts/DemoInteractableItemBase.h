#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DemoInteractableItemBase.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class CHARACTERSHOWCASE_API ADemoInteractableItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ADemoInteractableItemBase();

protected:
	virtual void BeginPlay() override;


public:	
	virtual void Tick(float DeltaTime) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<USphereComponent> InteractableSphere;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<UStaticMeshComponent> MeshComponent;
};
