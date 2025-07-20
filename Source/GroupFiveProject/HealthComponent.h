// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GROUPFIVEPROJECT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnTakeAnyDamage(AActor *DamageActor,
						 float Damage,
						 const class UDamageType *DamageType,
						 class AController *InstigateBy,
						 AActor *DamageCauser);

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UFUNCTION(BlueprintPure)
	float GetCurrentHealth();

	UFUNCTION(BlueprintPure)
	float GetDamagePercent();

	UFUNCTION(BlueprintCallable)
	void Heal(float healAmount);

	UFUNCTION(BlueprintCallable)
	void Damage(float damageAmount);

	UFUNCTION(BlueprintPure)
	bool IsDead();

protected:
	UPROPERTY(EditDefaultsOnly)
	float CurrentHealth = 100.0f;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100.0f;
};
