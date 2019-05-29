// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 Max downward speed and +1 mas up movement
	void Elevate(float RelativeSpeed);//поднять ствол градусы в секунду 

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 10;//Макс. Градусов в секунду

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40;//	Максимальный уровень повышения

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;// 	
};
