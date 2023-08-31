// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"


// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	FString name = GetName();

	UE_LOG(LogTemp, Display, TEXT("Actor Name : %s"), *name);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	CurrentLocation += PlatformVelocity * DeltaTime;

	SetActorLocation(CurrentLocation);

	MovedDistance = FVector::Dist(StartLocation, CurrentLocation);

	if (MovedDistance > TargetDistance)
	{
		StartLocation = StartLocation + (TargetDistance * PlatformVelocity.GetSafeNormal());
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

