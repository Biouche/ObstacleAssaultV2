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

	initialZPos = GetActorLocation().Z;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector temp = GetActorLocation();

	if (temp.Z > initialZPos + ZBounceDelta)
		PlatformVelocity = -PlatformVelocity;

	if (temp.Z < initialZPos)
		PlatformVelocity = -PlatformVelocity;

	temp += PlatformVelocity * DeltaTime;


	SetActorLocation(temp);

}

