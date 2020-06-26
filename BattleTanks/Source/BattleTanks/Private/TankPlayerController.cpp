// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Camera/PlayerCameraManager.h"
#include "Tank.h"
#include "BattleTanks.h"


//
    void ATankPlayerController::BeginPlay() 
{
    Super::BeginPlay();
    auto ControlledTank = GetControlledTank();

    if(!ControlledTank)
    {   
        UE_LOG(LogTemp, Error, TEXT("No player attached to player tank"));
    }

    if(ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Tank player found %s"), *ControlledTank->GetName());
    }

}


void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //AimTowardsCrosshair

    AimTowardsCrosshair();
}




//
    void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank()){return;}

    FVector HitLocation; //outparameter
    if(GetSightRayHitLocation(HitLocation))// Has "Side-Effect", is going to line trace
        {
            GetControlledTank()->AimAt(HitLocation); 
            //TODO tell the controlled tank to aim at this point
        }
}


ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{

    //Find the crosshair position in pixel coordinates
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY );
    auto ScreenLocation = FVector2D((CrossHairXLocation*ViewportSizeX), (CrossHairYLocation*ViewportSizeY));
    
    //"De-Project" The screen position of the crosshair to a world direction
    FVector LookDirection;
    if(GetLookDirection(ScreenLocation, LookDirection))
    {
        GetLookVectorHitLocation(LookDirection, OutHitLocation);
        
    }



    return true;

}

bool ATankPlayerController::GetLookDirection (FVector2D ScreenLocation, FVector& LookDirection)const
{
    //"De-Project" The screen position of the crosshair to a world direction
    FVector WorldLocaiton; // to be discarded
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocaiton, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
    FHitResult HitResult;
    auto StartLocation = PlayerCameraManager->GetCameraLocation();
    auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
    if (GetWorld()->LineTraceSingleByChannel(
        HitResult,
        StartLocation,
        EndLocation,
        ECollisionChannel::ECC_Visibility)
    )

    {
       HitLocation = HitResult.Location;
        return true;
    }
        HitLocation = FVector (0); //Assigned in case we get some nasty value
        return false;
    

}



