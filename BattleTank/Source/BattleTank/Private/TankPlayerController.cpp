// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	FVector HitLocation; // OutParameter

	if (bGetSightRayHitLocation(HitLocation))
	{
		
		if (!GetControllerTank()) { return; }
	}
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControllerTank = GetControllerTank();
	if (!ControllerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not Possessig a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possessig: %s "), *(ControllerTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

bool ATankPlayerController::bGetSightRayHitLocation(FVector& HitLocation) const
{
	//найти расположение прицела 
	int32 ViewportSizeX, ViewportSizeY; //out parameter Размер текущего экрана

	GetViewportSize(ViewportSizeX, ViewportSizeY);// получает размер экрана 
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s "), (*ScreenLocation.ToString()));

	//Депроджект - положение экрана , куросора или прицела 
	//лайн трейс в направление прицела , показывает что в конечном этоге мы удрим 
	return true;
}
