// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Components/ActorComponent.h"
#include "GameFrameWork/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
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

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
	{
		Barrel = BarrelToSet;
	}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
	{
		UE_LOG(LogTemp, Warning , TEXT("aiming at %f"), LaunchSpeed);
	}

