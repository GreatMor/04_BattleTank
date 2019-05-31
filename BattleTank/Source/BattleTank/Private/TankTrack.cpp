// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto  NameTrack = GetWorld()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s tThrottle: %f "), *NameTrack, Throttle);
}

