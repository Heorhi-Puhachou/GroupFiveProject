// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolPointsComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GROUPFIVEPROJECT_API UPatrolPointsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPatrolPointsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

protected:
	FVector NorthPoint;
	
	FVector EastPoint;
	
	FVector SouthPoint;
	
	FVector WestPoint;

	UPROPERTY(EditAnywhere)
	float PatrolRadius = 2000.0f;

	std::vector<FVector> PatrolPoints;

	//  dwa tryby patrolowania: cyklicznie (true) i ze zmianą kierunku (false)
	UPROPERTY(EditDefaultsOnly)
	bool CyclePatrol = false;

	int MaxPatrolPointsIndex;

	int CurrentPatrolPointIndex = 0;

public:

	UFUNCTION(BlueprintPure)
	FVector GetNextPoint();
};
