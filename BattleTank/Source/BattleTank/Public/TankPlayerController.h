// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Camera/PlayerCameraManager.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank* GetControllerTank() const; // ������ ��������� �� ���� ����� TankPlayerController ���� ����� ������ ��������� 

	void AimTowardsCrosshair(); // ������������ ����� ������ 
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	bool GetSightRayHitLocation(FVector& HitLocation) const;// ���������� ���� ������ ������ ���������� 
	
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;// ���������� �������  �� �������� �� ��� �

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333f;// ���������� ������� �� �������� �� ��� Y

	UPROPERTY(EditAnywhere)
	float LainTraceRange = 1000000;//LainTraceRange ��� ������� ��������� ���������� 

	bool bGetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;//������ LookDirection

	bool GetLookVectorHitLocation(FVector LookDerection, FVector& HitLocation) const;
};