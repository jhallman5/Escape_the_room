// Copywrite John Hallman 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BIUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
    
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
    void OpenDoor();
    void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    
		
private:
    UPROPERTY(VisibleAnywhere)
    float OpenAngle = -90.f;

    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate;
    
    UPROPERTY(EditAnywhere)
    float CloseDoorDelay = 0.5f;
    
    float LastTimeOpened;
    
    AActor* ActorThatOpens;
    
};
