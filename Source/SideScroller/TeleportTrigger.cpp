// Fill out your copyright notice in the Description page of Project Settings.
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

#include "TeleportTrigger.h"
#include "SideScrollerCharacter.h"
#include "DrawDebugHelpers.h"


ATeleportTrigger::ATeleportTrigger()
{
	EntranceMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EntranceMesh"));
	EntranceMesh->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
}

void ATeleportTrigger::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);

}

void ATeleportTrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	auto Character = Cast<ASideScrollerCharacter>(OtherActor);
	if (Character)
	{

		print("Overlap Begin | TELEPORTING");
		printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
		//UKismetSystemLibrary::PrintString(this, "Overlap begin", true, true, FLinearColor(0.0f, 0.6f, 1.0f, 1.0f));
	}
}