// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "LightAnimatorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CGGAME_API ULightAnimatorComponent : public USceneComponent
{
	GENERATED_BODY()

	int32 StepIndex;

	float StepAccumulator;

public:	

	UPROPERTY()
	float StepInterval;

	// Sets default values for this component's properties
	ULightAnimatorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
