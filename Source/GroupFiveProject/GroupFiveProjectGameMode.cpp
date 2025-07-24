// Copyright Epic Games, Inc. All Rights Reserved.

#include "GroupFiveProjectGameMode.h"
#include "GroupFiveProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGroupFiveProjectGameMode::AGroupFiveProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
