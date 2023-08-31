// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatformWithTargetLocation.generated.h"

UCLASS()
class OBSTACLEASSAULTV2_API AMovingPlatformWithTargetLocation : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatformWithTargetLocation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MovePlatform(float DeltaTime);
	bool ShouldPlatformReturn() const;

	UPROPERTY(EditAnywhere, Category = "Moving")
	AActor* TargetActor;

	UPROPERTY(EditAnywhere, Category = "Moving")
	FVector PlatformVelocity = FVector(0, 1, 0);

	UPROPERTY(VisibleAnywhere, Category = "Moving")
	FVector StartLocation = FVector(0, 0, 0);

	UPROPERTY(VisibleAnywhere, Category = "Moving")
	FVector TargetLocation = FVector(0, 0, 0);


};
