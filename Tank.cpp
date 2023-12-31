// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AmingTankComponent = CreateDefaultSubobject<UAmingTankComponent>(FName("Aming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SightOn(FVector HitLocation)
{
	AmingTankComponent -> SightAt(HitLocation, BulletSpeed);



	//auto OurTankName = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s HitLocation  %s"), *OurTankName, *HitLocation.ToString());

}
void ATank::SetGunReference(UStaticMeshComponent* GunToSet)
{
	AmingTankComponent->SetGunReference(GunToSet);


}

