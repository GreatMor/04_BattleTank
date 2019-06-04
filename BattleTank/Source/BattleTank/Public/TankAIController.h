// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "Engine/World.h"
#include "TankPlayerController.h"
#include "GameFramework/PlayerController.h"
#include "TankAIController.generated.h"
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:

	float AcceptanceRadius = 3000.f;// аи приблизится на 30 метров(3000см)
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime)override;
	
};
