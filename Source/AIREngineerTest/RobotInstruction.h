// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RobotInstruction.generated.h"

/*  */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API URobotInstruction : public UObject
{
	GENERATED_BODY()

public:
	URobotInstruction();	

	UFUNCTION(BlueprintCallable)
		bool ExecuteInstruction();
};
