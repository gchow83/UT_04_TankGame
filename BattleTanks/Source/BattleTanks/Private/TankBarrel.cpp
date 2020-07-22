// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate (float DegreesPerSecond)
{
    //move the barrel the right amount this frame
	//given a max elevation and frame time;
    UE_LOG(LogTemp, Warning, TEXT("Barrel-Elevate call: %f"), DegreesPerSecond);

}