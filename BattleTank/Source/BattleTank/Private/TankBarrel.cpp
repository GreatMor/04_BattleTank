// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
UTankBarrel::UTankBarrel()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankBarrel::Elevate(float RelativeSpeed)
{
	
//переместить на нужную велечину 

// Дать максимаьную высоту

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	
	
	SetRelativeRotation(FRotator(Elevation, 0, 0));

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("World %f"), RawNewElevation));
}