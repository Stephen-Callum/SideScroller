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

	bDoorIsUnlocked = false;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	// spawn corresponding key
}

void ADoor::OpenDoor(AKeyTrigger * Key)
{
	if (Key == CorrespondingKey && Key->bIsPickedUp)
	{
		// door opening logic...
		UKismetSystemLibrary::PrintString(this, "Key Picked up for door", true, true, FLinearColor(0.0f, 0.6f, 1.0f, 1.0f));
		bDoorIsUnlocked = true;
	}
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateDoor();
}

void ADoor::SetKey(AKeyTrigger * Key)
{
	CorrespondingKey = Key;
	CorrespondingKey->BindKeyDelegateExecutionFunction(this, FName("OpenDoor"));
}

void ADoor::RotateDoor()
{
	DoorRotation = DoorMesh->GetRelativeRotation();

	if (bDoorIsUnlocked)
	{
		DoorMesh->SetRelativeRotation(FMath::Lerp(FQuat(DoorRotation), FQuat(FRotator(0.0f, 110.0f, 0.0f)), 0.01f));
	}
}

