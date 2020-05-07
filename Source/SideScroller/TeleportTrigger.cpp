// Fill out your copyright notice in the Description page of Project Settings.
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

#include "TeleportTrigger.h"

ATeleportTrigger::ATeleportTrigger()
{
}

void ATeleportTrigger::BeginPlay()
{
	Super::BeginPlay();
}

void ATeleportTrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		print("Overlap Begin | TELEPORTING");
		printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
		//UKismetSystemLibrary::PrintString(this, "Overlap begin", true, true, FLinearColor(0.0f, 0.6f, 1.0f, 1.0f));
	}
}