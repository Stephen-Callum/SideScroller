// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBoxTrigger.h"
#include "KeyTrigger.generated.h"

/**
 * 
 */
DECLARE_DELEGATE_OneParam(FDoorKeyPickedUp, AKeyTrigger*);

UCLASS()
class SIDESCROLLER_API AKeyTrigger : public ABaseBoxTrigger
{
	GENERATED_BODY()

public:
	AKeyTrigger();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* KeyMesh;

	bool bIsPickedUp;

protected:
	virtual void BeginPlay() override;

public:
	virtual void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor) override;

	void BindKeyDelegateExecutionFunction(UObject* InUserObject, FName FuncName);

	//UFUNCTION(BlueprintCallable)
	FDoorKeyPickedUp OnKeyPickUp;
};
