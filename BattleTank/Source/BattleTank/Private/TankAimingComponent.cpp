// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick =  false; 
}
void  UTankAimingComponent::Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;// Out Parameter
	FVector StartLocation = Barrel->GetSocketLocation(FName("LaunchLocation"));
	bool bHaveAimSolution = (UGameplayStatics::SuggestProjectileVelocity
		( // ��������� �������� ������� �������, ����� ������� � ��������� �����.
			this,
			OutLaunchVelocity,
			StartLocation,
			HitLocation,
			LaunchSpeed,
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace
		)
	);

		if (bHaveAimSolution)		
		{
			//	Calculate the OutLaunchVelocity.
			auto AimDirection = OutLaunchVelocity.GetSafeNormal();
			MoveBarrelTowards(AimDirection);
			auto Time = GetWorld()->GetTimeSeconds();
			//UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), Time);
		}	
		else
		{
			auto Time = GetWorld()->GetTimeSeconds();
			//UE_LOG(LogTemp, Warning, TEXT("%f: No aim solve found"), Time);
		}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{	
	if (!Barrel || !Turret) { return; }

	auto BarrelRotation = Barrel->GetForwardVector().Rotation();//�������� ������ (X) ������ ����������� ������� �� ����� ���������� � ������� ������������.
	auto AimAsRotation = AimDirection.Rotation();// ���� �����������
	auto DeltaRotator = AimAsRotation - BarrelRotation;//

	if (FMath::Abs(DeltaRotator.Yaw) > 180.f)
	{
		DeltaRotator.Yaw *= (-1.f);
	}

	Barrel->Elevate(DeltaRotator.Pitch);

	Turret->Rotate(DeltaRotator.Yaw);
}

