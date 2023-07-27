// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FOGAME_01_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void TankAiming();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetViewDerection(FVector2D ScreenLocation, FVector& WorldDerection) const;

	bool GetLookVectirHitLocation(FVector LookDerection, FVector& HitLocation) const;

public:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.35;

	UPROPERTY(EditAnywhere)
	float LineTraceRanch = 1000000;

};
