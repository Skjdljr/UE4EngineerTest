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

	/*The actor class to spawn by dropper robot*/
	UPROPERTY(EditAnyWhere)
	TSubclassOf<AActor> ActorToSpawn;

	//Offset from robot to spawn from, use a positive value
	UPROPERTY(EditAnyWhere)
	FVector spawnOffset;

	/*
	* DropSphere 
	*/
	void ExecuteInstruction(ABaseRobot* robot) final;

	bool IsComplete() final;
};
