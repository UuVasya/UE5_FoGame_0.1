// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController WORK"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController  %s"), *(PlayerTank->GetName()));
	}

}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	GetControlledTank()->SightOn(GetPlayerTank()->GetActorLocation());

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto FirstPlayerPawn= GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!FirstPlayerPawn) { return nullptr; }

	return Cast<ATank>(FirstPlayerPawn);
	
}
