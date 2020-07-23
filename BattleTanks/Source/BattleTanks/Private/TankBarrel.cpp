// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate (float RelativeSpeed)
{
    //move the barrel the right amount this frame
	//given a max elevation and frame time;
    auto Time = GetWorld()->GetTimeSeconds();
    UE_LOG(LogTemp, Warning, TEXT("%f: Barrel-Elevate call: %f"), Time, RelativeSpeed);

}