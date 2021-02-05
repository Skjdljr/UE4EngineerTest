// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AirEngineerTest/RobotInstruction.h"
#include "Instruction_MoveForward.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API UInstruction_MoveForward : public URobotInstruction
{
	GENERATED_BODY()

	UInstruction_MoveForward();

	/*
	* Set the distance to move
	*/
	UPROPERTY(EditAnywhere)
	float distanceToMove;

	void ExecuteInstruction(ABaseRobot* robot) final;

	bool IsComplete() final;
};
