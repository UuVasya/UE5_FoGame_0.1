// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "AmingTankComponent.h"

// Sets default values for this component's properties
UAmingTankComponent::UAmingTankComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}

void UAmingTankComponent::SetGunReference(UStaticMeshComponent* GunToSet)
{
	Gun = GunToSet;
}

// Called when the game starts
void UAmingTankComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UAmingTankComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAmingTankComponent::SightAt(FVector HitLocation, float BulletSpeed)
{
	if (!Gun) { return; }
	FVector OutTossVelocity;
	FVector StartLocation = Gun->GetSocketLocation(FName("Projecity"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		Gun,
		OutTossVelocity,
		StartLocation,
		HitLocation,
		BulletSpeed,
		false,
		0.0F,
		0.0F,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if(bHaveAimSolution)
	{
	FVector AimDerection = OutTossVelocity.GetSafeNormal();
	FString OurTankName = GetOwner()->GetName();

	MoveGun(AimDerection);

	//UE_LOG(LogTemp, Warning, TEXT("%s aming at  %s"), *OurTankName, *AimDerection.ToString());
	};
	//auto OurTankName =GetOwner()-> GetName();
	//auto GunLocation = Gun->GetComponentLocation().ToString();
	//UE_LOG(LogTemp, Warning, TEXT("%s aming at  %s from %s"), *OurTankName, *HitLocation.ToString(), *GunLocation);
}

void UAmingTankComponent::MoveGun(FVector AimDerection)
{
	auto GunRotator = Gun->GetForwardVector().Rotation();
	auto AimRotator = AimDerection.Rotation();

	UE_LOG(LogTemp, Warning, TEXT("Aming at  %s"), *AimRotator.ToString());
}