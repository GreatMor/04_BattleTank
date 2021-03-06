// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControllerTank = GetControllerTank();
	if (!ControllerTank)
	{}
	else
	{}
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

	if (GetSightRayHitLocation(HitLocation)) // ����� �������� ���������� 
	{		
		GetControllerTank()->AimAt(HitLocation);
	}
}

// �������� ������� �������������� ����� ����������� ����� �����������, true ���� ������� � ��������
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//����� ������������ ������� � ���������� ����������� 
	int32 ViewportSizeX, ViewportSizeY; //out parameter ������ �������� ������

	GetViewportSize(ViewportSizeX, ViewportSizeY);// �������� ������ ������ 
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);	

	//���������� - ��������� ������ , �������� ��� ������� 

	FVector LookDirection;//Out parameter
	if (bGetLookDirection(ScreenLocation,LookDirection))
	{
		//���� ����� � ����������� LookDirection , ���������� ��� � �������� ����� �� ����� 
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
		);//�������������� 2D-��������� ������ � World Space 3D-��������� 	
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDerection, FVector& HitLocation) const
{
	FHitResult HitResult;// parameter for LineTraceSingleByChannel (struct FHitResult & OutHit,) return HitResult(����� ����� ����)
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
