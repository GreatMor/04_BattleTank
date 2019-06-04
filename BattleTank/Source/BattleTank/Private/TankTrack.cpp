// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto  NameTrack = GetWorld()->GetName();
	

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;//Приложенная сила 
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast <UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

