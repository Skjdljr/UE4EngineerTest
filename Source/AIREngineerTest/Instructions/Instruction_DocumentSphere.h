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

	UPROPERTY(EditAnyWhere)
	float reasonableDistance;

	UFUNCTION(BlueprintCallable)
	void SetClosestSphereFromBP(AActor* sphere, float distance);

	void ExecuteInstruction(ABaseRobot* robot) final;

	bool IsComplete() final;

	private:

	//Find the actors that are currently on screen
	void FindActorsInView(TArray<AActor*>& onScreenActors);

	//Save the actors found on screen to a file
	void SaveActorsToFile(TArray<AActor*>& onScreenActors);
};
