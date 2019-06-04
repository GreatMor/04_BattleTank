// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(blueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TrackMaxDrivingForce = 12000000;//Максимальная силна на track в Ньютонах

};
