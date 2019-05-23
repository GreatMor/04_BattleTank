// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;// Out Parameter
	FVector StartLocation = Barrel->GetSocketLocation(FName("LaunchLocation"));
	bool bHaveAimSolution = (UGameplayStatics::SuggestProjectileVelocity
		( // Вычисляет скорость запуска снаряда, чтобы попасть в указанную точку.
			this,
			OutLaunchVelocity,
			StartLocation,
			HitLocation,
			LaunchSpeed,
			ESuggestProjVelocityTraceOption::DoNotTrace
		)
	);

		if (bHaveAimSolution)		
		{
			//	Calculate the OutLaunchVelocity.
			auto AimDirection = OutLaunchVelocity.GetSafeNormal();
			MoveBarrelTowards(AimDirection);
		}	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{	
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();//Получите прямой (X) вектор направления единицы из этого компонента в мировом пространстве.
	auto AimAsRotation = AimDirection.Rotation();// цель направления
	auto DeltaRotator = AimAsRotation - BarrelRotation;//

	Barrel->Elevate(5);
}

