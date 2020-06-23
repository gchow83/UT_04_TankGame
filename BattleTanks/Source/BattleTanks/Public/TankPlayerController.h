// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "TankPlayerController.generated.h" //must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

	private:

		ATank* GetControlledTank() const;
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
		void AimTowardsCrosshair();
		bool GetSightRayHitLocation(FVector& HitLocation) const;
		bool HitSurface;
		bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
		UPROPERTY(EditAnyWhere)
		float LineTraceRange = 1000000;

		bool GetLookDirection (FVector2D ScreenLocation, FVector& LookDirection) const;

		UPROPERTY(EditAnywhere)
		float CrossHairXLocation = .5;
		UPROPERTY(EditAnywhere)
    	float CrossHairYLocation = .333333;
    
};
