// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AirEngineerTest/RobotInstruction.h"
#include "Instruction_DropSphere.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API UInstruction_DropSphere : public URobotInstruction
{
	GENERATED_BODY()

	UInstruction_DropSphere();

	//Set the spawnlocation vector from BP
	UFUNCTION(BlueprintCallable)
	void SetSpawnLocationForDroppables(FVector spawnLocation);

	/*
	* DropSphere 
	*/
	void ExecuteInstruction(ABaseRobot* robot) final;

	bool IsComplete() final;

private:
	ABaseRobot* callingRobot;
};
