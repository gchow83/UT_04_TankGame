// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    auto ControlledTank = GetPlayerTank();

    if(!ControlledTank)
    {   
        UE_LOG(LogTemp, Error, TEXT("Can't find the player tank"));
    }

    if(ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerTank Found %s"), *ControlledTank->GetName());
    }

}

void ATankAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    
   if(GetPlayerTank())
   {
    FVector PlayerOnePoistion = GetPlayerTank()->GetActorLocation();
    GetControlledTank()->AimAt(PlayerOnePoistion); 
   }


}


ATank* ATankAIController::GetControlledTank() const
    {
        return Cast<ATank>(GetPawn());
    }  

ATank* ATankAIController::GetPlayerTank() const
    {
        auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
        if(!PlayerPawn) {return nullptr;}
        return Cast<ATank> (PlayerPawn);

    }