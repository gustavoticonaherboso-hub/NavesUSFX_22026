// Copyright Epic Games, Inc. All Rights Reserved.

#include "USFX4GameMode.h"
#include "USFX4Pawn.h"

AUSFX4GameMode::AUSFX4GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AUSFX4Pawn::StaticClass();
}

