// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AmmoComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmmoChangedDelegate, int, CurrentAmmo, int, MaxAmmo);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GROUPFIVEPROJECT_API UAmmoComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAmmoComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UFUNCTION(BlueprintPure)
	int GetCurrentAmmo();

	UFUNCTION(BlueprintPure)
	bool HasAmmo();

	UFUNCTION(BlueprintCallable)
	void addAmmo(int amount);

	UFUNCTION(BlueprintCallable)
	void useAmmo();

	UPROPERTY(BlueprintAssignable)
	FOnAmmoChangedDelegate OnAmmoChanged;

protected:
	UPROPERTY(EditDefaultsOnly)
	int CurrentAmmo = 0;

	UPROPERTY(EditDefaultsOnly)
	int MaxAmmo = 100;

private:
	void printLog(std::string string, int number);
};
