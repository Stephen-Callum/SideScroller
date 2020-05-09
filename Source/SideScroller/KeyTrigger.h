// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBoxTrigger.h"
#include "KeyTrigger.generated.h"

/**
 * 
 */
UCLASS()
class SIDESCROLLER_API AKeyTrigger : public ABaseBoxTrigger
{
	GENERATED_BODY()

public:
	AKeyTrigger();

	UStaticMeshComponent* KeyMesh;

	bool bIsPickedUp;

protected:
	virtual void BeginPlay() override;

public:
	virtual void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor) override;
};
