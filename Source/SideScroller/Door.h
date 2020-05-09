// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KeyTrigger.h"
#include "Door.generated.h"

UCLASS()
class SIDESCROLLER_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

	UPROPERTY(EditAnywhere, Category = "Door")
	UStaticMeshComponent* DoorFrameMesh;

	UPROPERTY(EditAnywhere, Category = "Door")
	UStaticMeshComponent* DoorMesh;

	AKeyTrigger* CorrespondingKey;

	UPROPERTY(BlueprintReadWrite)
	FTransform KeySpawnPoint;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AKeyTrigger> KeyToSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OpenDoor(AKeyTrigger* Key);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SpawnKey(FVector Loc, FRotator Rot);
};
