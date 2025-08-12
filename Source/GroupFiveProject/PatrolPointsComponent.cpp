// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolPointsComponent.h"
#include "Algo/Reverse.h"

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


	if (!CyclePatrol)
	{
		TArray<FVector> Reversed = PatrolPoints;
		Algo::Reverse(Reversed);

		TArray<FVector> OriginalAndReversedArray;

		// Add original array
		for (FVector point : PatrolPoints)
		{
			OriginalAndReversedArray.Add(point);
		}

		// Not included first and last reversed elements to prevent duplicates on path:
		// 1 2 3 4 (4) 3 2 (1)
		for (int i = 1; i < PatrolPoints.Num() - 1; i++)
		{
			OriginalAndReversedArray.Add(Reversed[i]);
		}
		PatrolPoints = OriginalAndReversedArray;
	}
	MaxPatrolPointsIndex = PatrolPoints.Num();
}


// Called every frame
void UPatrolPointsComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
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
