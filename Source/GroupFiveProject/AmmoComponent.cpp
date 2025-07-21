// Fill out your copyright notice in the Description page of Project Settings.

#include "AmmoComponent.h"

#include <sstream>

// Sets default values for this component's properties
UAmmoComponent::UAmmoComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

// Called when the game starts
void UAmmoComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UAmmoComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int UAmmoComponent::GetCurrentAmmo()
{
	return CurrentAmmo;
}

bool UAmmoComponent::HasAmmo()
{
	return CurrentAmmo > 0;
}

void UAmmoComponent::addAmmo(int amount)
{
	CurrentAmmo += amount;
	CurrentAmmo = FMath::Clamp(CurrentAmmo, 0, MaxAmmo);

	OnAmmoChanged.Broadcast(CurrentAmmo, MaxAmmo);
}

void UAmmoComponent::printLog(std::string string, int number)
{
	std::ostringstream ss;
	ss << number;
	std::string s(ss.str());

	std::string someString = string + s;
	FString layerName(someString.c_str());
	UE_LOG(LogTemp, Warning, TEXT("%s"), *layerName);
}

void UAmmoComponent::useAmmo()
{
	//printLog("Max - ", MaxAmmo);
	//printLog("Current - ", CurrentAmmo);
	if (CurrentAmmo > 0)
	{
		CurrentAmmo--;
		OnAmmoChanged.Broadcast(CurrentAmmo, MaxAmmo);
	}
	//printLog("After use - ", CurrentAmmo);
}
