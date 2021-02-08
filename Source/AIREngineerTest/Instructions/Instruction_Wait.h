// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AirEngineerTest/RobotInstruction.h"
#include "Instruction_Wait.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API UInstruction_Wait : public URobotInstruction
{
	GENERATED_BODY()

public:
	UInstruction_Wait();

	/*
	* Time to delay/wait
	*/
	UPROPERTY(EditAnywhere)
	float waitTime;
	
	void ExecuteInstruction(ABaseRobot* robot) final;

	bool IsComplete() final;

private:
	FTimerHandle timerHandle;
	void TimerElapsed();
};
