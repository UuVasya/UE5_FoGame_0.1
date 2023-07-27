// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlTank = GetControlledTank();
	if (!ControlTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController WORK"));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController  %s"),*(ControlTank->GetName()));
	}
	
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TankAiming();
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::TankAiming() 
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->SightOn(HitLocation);
	}
	
};

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	FVector2D ScreenLocation = FVector2D(ViewPortSizeX, ViewPortSizeY) * FVector2D(CrossHairXLocation, CrossHairYLocation);
	
	FVector LookDerection;
	if (GetViewDerection(ScreenLocation, LookDerection)) 
	{
		//UE_LOG(LogTemp, Warning, TEXT("View  %s"), *LookDerection.ToString());
		GetLookVectirHitLocation(LookDerection, OutHitLocation);
	}
	
	return true;
}

bool ATankPlayerController::GetViewDerection(FVector2D ScreenLocation, FVector& WorldDerection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDerection);
	//

	
}

bool ATankPlayerController::GetLookVectirHitLocation(FVector LookDerection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + LookDerection * LineTraceRanch;

	
	if(GetWorld()->LineTraceSingleByChannel
	(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}
