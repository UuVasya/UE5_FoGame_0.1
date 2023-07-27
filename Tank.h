// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "AmingTankComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class FOGAME_01_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	void SightOn (FVector HitLocation);
	ATank();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UAmingTankComponent* AmingTankComponent= nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetGunReference(UStaticMeshComponent* GunToSet);

	UPROPERTY(EditAnywhere,Category = Firing)
	float BulletSpeed = 100000;
};
