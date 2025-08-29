// Fill out your copyright notice in the Description page of Project Settings.


#include "LightAnimatorComponent.h"

// Sets default values for this component's properties
ULightAnimatorComponent::ULightAnimatorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void ULightAnimatorComponent::BeginPlay()
{
	Super::BeginPlay();

	//ULightComponentBase* TheLightByParent = Cast<ULightComponentBase>(GetAttachParent());
	//if (TheLightByParent)
	//{
	//	TargetLight->Intensity = 9001.0f;
	//}
}

// Called every frame
void ULightAnimatorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//StepAccumulator += DeltaTime;

	//// TODO: cap accumulator?

	//while (StepAccumulator >= StepInterval)
	//{
	//	StepAccumulator -= StepInterval;
	//	StepIndex = ++StepIndex % Pattern.Len();

	//	TCHAR CurrentChar = Pattern[StepIndex];
	//	int BeginRange = FChar::ConvertCharDigitToInt(TCHAR('a'));
	//	int EndRange = FChar::ConvertCharDigitToInt(TCHAR('m'));
	//	int CurValue = FChar::ConvertCharDigitToInt(CurrentChar);
	//	// Get range as Percentage (Pct) expressed as a 0.0 to 1.0 value
	//	float Alpha = FMath::GetRangePct((float)BeginRange, (float)EndRange, (float)CurValue);

	//	TargetLight->SetIntensity(MaxIntensity * Alpha)
	//}
}