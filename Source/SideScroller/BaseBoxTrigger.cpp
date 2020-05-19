// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

#include "BaseBoxTrigger.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"


ABaseBoxTrigger::ABaseBoxTrigger()
{
}

void ABaseBoxTrigger::BeginPlay()
{
	Super::BeginPlay();

}

void ABaseBoxTrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	//UKismetSystemLibrary::PrintString(this, "Overlap begin", true, true, FLinearColor(0.0f, 0.6f, 1.0f, 1.0f));

	if (OtherActor && (OtherActor != this))
	{
		print("Overlap Begin");
		printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
		//UKismetSystemLibrary::PrintString(this, "Overlap begin", true, true, FLinearColor(0.0f, 0.6f, 1.0f, 1.0f));
	}
}

void ABaseBoxTrigger::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		print("Overlap End");
		printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
		//UKismetSystemLibrary::PrintString(this, "Overlap end", true, true, FLinearColor(0.0f, 0.6f, 1.0f, 1.0f));
	}
}
