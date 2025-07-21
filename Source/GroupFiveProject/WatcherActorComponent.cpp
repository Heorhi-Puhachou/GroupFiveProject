// Fill out your copyright notice in the Description page of Project Settings.

#include "WatcherActorComponent.h"

// Sets default values for this component's properties
UWatcherActorComponent::UWatcherActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UWatcherActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UWatcherActorComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	// Lepiej byłoby najpierw sprawdzić sam dystans, jeżeli jesteśmy za daleko to już nie ma sansu robić Trace'a (który jest kosztowny).
	// Sam dystans też lepiej byłoby porównywać w formie skwadratowanej. Pomocnicze zmienne (np PlayerLocation ) powinny być const,

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	const FVector ObjectLocation = GetOwner()->GetActorLocation();
	const float Distance = FVector::Dist(PlayerLocation, ObjectLocation);

	if (ReactionDistance > Distance)
	{
		FHitResult Result;
		GetWorld()->LineTraceSingleByChannel(Result, PlayerLocation, ObjectLocation, ECollisionChannel::ECC_Visibility);
		const bool isPlayerVisible = Result.GetActor() == GetOwner();
		if (isPlayerVisible)
		{
			const FRotator FacingRotator = (PlayerLocation - ObjectLocation).Rotation();
			GetOwner()->SetActorRotation(FacingRotator, ETeleportType::None);
		}
	}
}
