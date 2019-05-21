// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank* GetControllerTank() const; // вернёт указатель на танк чтобы TankPlayerController знал каким танком управлять 

	void AimTowardsCrosshair(); // прицеливание через прицел 
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	bool bGetSightRayHitLocation(FVector& HitLocation) const;// направляет лучь сквозь прицел трасировка 
	
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;// координаты курсора на мониторе по оси Х

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333f;// координаты курсора на мониторе по оси Y
};
