// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AirEngineerTest/RobotInstruction.h"
#include "Instruction_DocumentSphere.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API UInstruction_DocumentSphere : public URobotInstruction
{
	GENERATED_BODY()
	
	UInstruction_DocumentSphere();

	void ExecuteInstruction(ABaseRobot* robot) final;

	bool IsComplete() final;

	private:

	void FindActorsInView(TArray<AActor*>& onScreenActors);
	void SaveActorsToFile(TArray<AActor*>& onScreenActors);

};
