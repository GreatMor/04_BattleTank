// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"// состовная часть танка 
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	
	UFUNCTION(BlueprintCallable)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable)
	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector HitLOcation);

	UFUNCTION(BlueprintCallable)
	void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	UTankAimingComponent* TankAimingComponent = nullptr;// создаём указатель на компонент наведения 

public:	
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Shoots")
	float LaunchSpeed = 4000.f; // начальная скорость выстрела 1000 м/с

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf <AProjectile> ProjectileBlueprint;

	UTankBarrel * Barrel = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Shoots")
	float RelodingTimeInSeconds = 3;//Перезагружая время в секундах
	double LastFierTime = 0; 

};
