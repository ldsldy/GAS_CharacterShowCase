#include "Item/Interacts/DemoInteractableItemBase.h"

ADemoInteractableItemBase::ADemoInteractableItemBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ADemoInteractableItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADemoInteractableItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

