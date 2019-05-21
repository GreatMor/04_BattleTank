// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControllerTank = GetControllerTank();
	if (!ControllerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai controller not Possessig a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai controller  Possessig: %s "), *(ControllerTank->GetName()));
	}
}