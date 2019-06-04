// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Classes/AIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControllerTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);
		ControllerTank->AimAt(PlayerTank->GetActorLocation());
		ControllerTank->Fire();
	}
}



