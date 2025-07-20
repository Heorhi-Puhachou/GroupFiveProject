// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OnTakeAnyDamage);
}

void UHealthComponent::OnTakeAnyDamage(AActor *DamageActor,
									   float DamageValue,
									   const UDamageType *DamageType,
									   AController *InstigateBy,
									   AActor *DamageCauser)
{
	Damage(DamageValue);
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UHealthComponent::GetCurrentHealth()
{
	return CurrentHealth;
}

float UHealthComponent::GetDamagePercent()
{
	return 1 - CurrentHealth / MaxHealth;
}

void UHealthComponent::Heal(float healAmount)
{
	CurrentHealth += healAmount;
	CurrentHealth = FMath::Clamp(CurrentHealth, 0, MaxHealth);
}

void UHealthComponent::Damage(float damageAmount)
{
	CurrentHealth -= damageAmount;
	CurrentHealth = FMath::Clamp(CurrentHealth, 0, MaxHealth);
}

bool UHealthComponent::IsDead()
{
	return CurrentHealth <= 0.0f;
}
