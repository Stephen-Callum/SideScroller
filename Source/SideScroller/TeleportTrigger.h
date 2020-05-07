// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBoxTrigger.h"
#include "TeleportTrigger.generated.h"

/**
 * 
 */
UCLASS()
class SIDESCROLLER_API ATeleportTrigger : public ABaseBoxTrigger
{
	GENERATED_BODY()
	
public:
	ATeleportTrigger();

protected:
	virtual void BeginPlay() override;

public:
	virtual void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor) override;
};
