// Fill out your copyright notice in the Description page of Project Settings.
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Orange,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT(text), fstring))

#include "KeyTrigger.h"
#include "SideScrollerCharacter.h"
#include "DrawDebugHelpers.h"


AKeyTrigger::AKeyTrigger()
{
	KeyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyMesh"));
	//KeyMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	KeyMesh->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false), "NAME_None");
}

void AKeyTrigger::BeginPlay()
{
	Super::BeginPlay();
	Sprite = GetSpriteComponent();
	bIsPickedUp = false;
	OnActorBeginOverlap.AddDynamic(this, &AKeyTrigger::OnOverlapBegin);
}

void AKeyTrigger::OnOverlapBegin(AActor * OverlappedActor, AActor * OtherActor)
{
	auto Character = Cast<ASideScrollerCharacter>(OtherActor);
	if (Character)
	{
		bIsPickedUp = true;
		print("Overlap Begin | Picking up key");
		printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
		OnKeyPickUp.Execute(this);
		if (OverlappedActor->Destroy())
		{
			print("destroyed");
		}
	}
}

void AKeyTrigger::BindKeyDelegateExecutionFunction(UObject * InUserObject, FName FuncName)
{
	OnKeyPickUp.BindUFunction(InUserObject, FuncName);
}

