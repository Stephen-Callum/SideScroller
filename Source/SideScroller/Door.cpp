// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorFrameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));

	DoorFrameMesh->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	DoorMesh->AttachToComponent(DoorFrameMesh, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	// spawn corresponding key
	SpawnKey(KeySpawnPoint.GetLocation(), KeySpawnPoint.GetRotation().Rotator());
	CorrespondingKey->BindKeyDelegateExecutionFunction(this, FName("OpenDoor"));
}

void ADoor::OpenDoor(AKeyTrigger * Key)
{
	if (Key == CorrespondingKey && Key->bIsPickedUp)
	{
		// door opening logic...
		UKismetSystemLibrary::PrintString(this, "Key Picked up for door", true, true, FLinearColor(0.0f, 0.6f, 1.0f, 1.0f));
	}
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoor::SpawnKey(FVector Loc, FRotator Rot)
{
	CorrespondingKey = GetWorld()->SpawnActor<AKeyTrigger>(KeyToSpawn, Loc, Rot);
}

