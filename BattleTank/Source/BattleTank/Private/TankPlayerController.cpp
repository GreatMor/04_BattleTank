// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControllerTank = GetControllerTank();
	if (!ControllerTank)
	{
		//UE_LOG(LogTemp, Warning, TEXT("PlayerController not Possessig a tank"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("PlayerController Possessig: %s "), *(ControllerTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	FVector HitLocation; // OutParameter	
		
	if (!GetControllerTank()) { return; }
	if (GetSightRayHitLocation(HitLocation)) // гетер проводит трасировку 
	{		
		UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());		
	}
}

// Получить мировое местоположение линии трассировки через перекрестие, true если попадет в ландшафт
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//найти расположение прицела в пиксельных координатах 
	int32 ViewportSizeX, ViewportSizeY; //out parameter Размер текущего экрана

	GetViewportSize(ViewportSizeX, ViewportSizeY);// получает размер экрана 
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);	

	//Депроджект - положение экрана , куросора или прицела 

	FVector LookDirection;//Out parameter
	if (bGetLookDirection(ScreenLocation,LookDirection))
	{
		//лайн трейс в направление LookDirection , показывает что в конечном этоге мы удрим 
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	
	return true;
}

bool ATankPlayerController::bGetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // out parameter 	
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
		);//Преобразование 2D-положения экрана в World Space 3D-положение 	
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDerection, FVector& HitLocation) const
{
	FHitResult HitResult;// parameter for LineTraceSingleByChannel (struct FHitResult & OutHit,) return HitResult(место удара луча)
	auto StartLocation = PlayerCameraManager->GetCameraLocation();// parameter for LineTraceSingleByChannel (Start)
	auto EndLocation = StartLocation + (LookDerection * LainTraceRange);// parameter for LineTraceSingleByChannel (end)

	if (GetWorld()->LineTraceSingleByChannel(  //Trace a ray against the world using a specific channel and return the first blocking hit
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	))
	{
		HitLocation = HitResult.Location;
		return true;
	}

	HitLocation = FVector(0);
	return false;
}
