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
	ATank* GetControllerTank() const; // вернёт указатель на танк чтобы TankPlayerController знал каким танком управлять 

private:	

	void AimTowardsCrosshair(); // прицеливание через прицел 
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	bool GetSightRayHitLocation(FVector& HitLocation) const;// направляет лучь сквозь прицел трасировка 
	
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;// координаты прицела  на мониторе по оси Х

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333f;// координаты прицела на мониторе по оси Y

	UPROPERTY(EditDefaultsOnly)
	float LainTraceRange = 1000000;//LainTraceRange для расчёта дальности трасировки 

	bool bGetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;//вернет LookDirection

	bool GetLookVectorHitLocation(FVector LookDerection, FVector& HitLocation) const;
};
