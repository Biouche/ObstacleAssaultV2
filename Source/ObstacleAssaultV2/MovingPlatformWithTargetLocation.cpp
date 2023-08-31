// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatformWithTargetLocation.h"

// Sets default values
AMovingPlatformWithTargetLocation::AMovingPlatformWithTargetLocation()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatformWithTargetLocation::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	TargetLocation = TargetActor->GetActorLocation();
}

// Called every frame
void AMovingPlatformWithTargetLocation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
}

void AMovingPlatformWithTargetLocation::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += PlatformVelocity * DeltaTime;
	SetActorLocation(CurrentLocation);

	if (ShouldPlatformReturn())
	{
		PlatformVelocity = -PlatformVelocity;
		TargetLocation = StartLocation;

		StartLocation = GetActorLocation();
	}
}

bool AMovingPlatformWithTargetLocation::ShouldPlatformReturn() const
{
	float distance = FVector::Distance(GetActorLocation(), TargetLocation);

	UE_LOG(LogTemp, Display, TEXT("Distance : %f"), distance);
	return distance < 10;
}
