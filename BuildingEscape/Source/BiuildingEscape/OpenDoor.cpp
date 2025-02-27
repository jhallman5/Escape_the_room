// Copywrite John Hallman 2018

#include "OpenDoor.h"
#include "Gameframework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
    
    ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
    // Find the owning Actor
    AActor* Owner = GetOwner();
    
    // Set the door rotation
    Owner->SetActorRotation(FRotator(0.f,OpenAngle,0.f));
}

void UOpenDoor::CloseDoor()
{
    // Find the owning Actor
    AActor* Owner = GetOwner();
    
    // Set the door rotation
    Owner->SetActorRotation(FRotator(0.f,0.0f,0.f));
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// poll the trigger volume every frame
    if (PressurePlate -> IsOverlappingActor(ActorThatOpens))
    {
        OpenDoor();
        LastTimeOpened = GetWorld()->GetTimeSeconds();
    }
    if (GetWorld()->GetTimeSeconds() - LastTimeOpened > CloseDoorDelay){
        CloseDoor();
    }
  
    
}

