// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "BaseBoxTrigger.generated.h"

/**
 * 
 */
UCLASS()
class SIDESCROLLER_API ABaseBoxTrigger : public ATriggerBox
{
	GENERATED_BODY()

public:
	ABaseBoxTrigger();

protected:
	virtual void BeginPlay() override;

public:
	
	UFUNCTION()
		void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor);
};
