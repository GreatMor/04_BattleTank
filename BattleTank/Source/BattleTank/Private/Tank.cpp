// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include  "TankBarrel.h"
#include  "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(TEXT("Aiming Component"));
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}
void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	/*FPlatformTime::Seconds() - LastFierTime) > RelodingTimeInSeconds;
	0  - 0 > 3 np
	1 - 0 > 3 no
	2 - 0 > 3 no 
	3 - 0 > 3 no 
	4 - 0 > 3 yes
	Projectile->LaunchProjectile(LaunchSpeed);// выстреливаем снаряд со скоростью
	LastFierTime = FPlatformTime::Seconds(); 
	 LastFierTime = 4
	4-4>3 no
	5-4>3 no
	6-4>3 no
	7-4>3 no
	8-4>3 yes 
	Projectile->LaunchProjectile(LaunchSpeed);// выстреливаем снаряд со скоростью
	LastFierTime = FPlatformTime::Seconds();
	 LastFierTime = 8

	*/
	bool isReloaded = (FPlatformTime::Seconds() - LastFierTime) > RelodingTimeInSeconds;//	если это вычетаниек больше чем перезагрузить 

	if (Barrel && isReloaded)//если есть ствол и мы перехаряжились 
	{
		auto Projectile = GetWorld()->SpawnActor <AProjectile>// создаём снаряд 
			(
				ProjectileBlueprint,
				Barrel->GetSocketLocation(FName("LaunchLocation")),
				Barrel->GetSocketRotation(FName(" LaunchLocation "))
			);

		Projectile->LaunchProjectile(LaunchSpeed);// выстреливаем снаряд со скоростью
		LastFierTime = FPlatformTime::Seconds();// последнее время выстрела меняяем с нуля на время последнего действия 
	}
}



// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

