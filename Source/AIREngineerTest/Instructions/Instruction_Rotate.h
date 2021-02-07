// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AirEngineerTest/RobotInstruction.h"
#include "Instruction_Rotate.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API UInstruction_Rotate : public URobotInstruction
{
	GENERATED_BODY()
	UInstruction_Rotate();

	/*
	* Amount to rotate
	*/
	UPROPERTY(EditAnywhere)
	float rotationAmount;

	UFUNCTION(BlueprintCallable)
	void SetComplete(bool complete);

	void ExecuteInstruction(ABaseRobot* robot) final;

	bool IsComplete() final;
};
