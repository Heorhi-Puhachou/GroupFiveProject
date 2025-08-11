// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolPointsComponent.h"

// Sets default values for this component's properties
UPatrolPointsComponent::UPatrolPointsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UPatrolPointsComponent::BeginPlay()
{
	Super::BeginPlay();

	const FVector NPCLocation = GetOwner()->GetActorLocation();

	NorthPoint = FVector(NPCLocation.X, NPCLocation.Y + PatrolRadius, NPCLocation.Z);
	EastPoint = FVector(NPCLocation.X + PatrolRadius, NPCLocation.Y, NPCLocation.Z);
	SouthPoint = FVector(NPCLocation.X, NPCLocation.Y - PatrolRadius, NPCLocation.Z);
	WestPoint = FVector(NPCLocation.X - PatrolRadius, NPCLocation.Y, NPCLocation.Z);

	PatrolPoints = {NorthPoint, EastPoint, SouthPoint, WestPoint, NorthPoint, WestPoint, SouthPoint, EastPoint};

	if (CyclePatrol)
	{
		MaxPatrolPointsIndex = 4;
	}
	else
	{
		MaxPatrolPointsIndex = PatrolPoints.size();
	}
}


// Called every frame
void UPatrolPointsComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FVector UPatrolPointsComponent::GetNorthPoint()
{
	return NorthPoint;
}

FVector UPatrolPointsComponent::GetEastPoint()
{
	return EastPoint;
}

FVector UPatrolPointsComponent::GetSouthPoint()
{
	return SouthPoint;
}

FVector UPatrolPointsComponent::GetWestPoint()
{
	return WestPoint;
}

FVector UPatrolPointsComponent::GetNextPoint()
{
	FVector ReturnValue = PatrolPoints[CurrentPatrolPointIndex];
	CurrentPatrolPointIndex++;
	if (CurrentPatrolPointIndex == MaxPatrolPointsIndex)
	{
		CurrentPatrolPointIndex = 0;
	}
	return ReturnValue;
}
