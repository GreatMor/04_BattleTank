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
protected:

	UFUNCTION(BlueprintCallable)
	ATank* GetControllerTank() const; // ����� ��������� �� ���� ����� TankPlayerController ���� ����� ������ ��������� 

private:	

	void AimTowardsCrosshair(); // ������������ ����� ������ 
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	bool GetSightRayHitLocation(FVector& HitLocation) const;// ���������� ���� ������ ������ ���������� 
	
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;// ���������� �������  �� �������� �� ��� �

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333f;// ���������� ������� �� �������� �� ��� Y

	UPROPERTY(EditDefaultsOnly)
	float LainTraceRange = 1000000;//LainTraceRange ��� ������� ��������� ���������� 

	bool bGetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;//������ LookDirection

	bool GetLookVectorHitLocation(FVector LookDerection, FVector& HitLocation) const;
};
