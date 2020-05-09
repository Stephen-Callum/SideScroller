// Fill out your copyright notice in the Description page of Project Settings.
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Orange,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT(text), fstring))

#include "KeyTrigger.h"
#include "SideScrollerCharacter.h"

AKeyTrigger::AKeyTrigger()
{
	KeyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyMesh"));
	KeyMesh->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
}

void AKeyTrigger::BeginPlay()
{
	Super::BeginPlay();

	bIsPickedUp = false;
}

void AKeyTrigger::OnOverlapBegin(AActor * OverlappedActor, AActor * OtherActor)
{
	auto Character = Cast<ASideScrollerCharacter>(OtherActor);
	if (Character)
	{
		print("Overlap Begin | Picking up key");
		printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
		bIsPickedUp = true;
		Destroy();
	}
}

