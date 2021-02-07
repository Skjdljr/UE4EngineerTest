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

	//Time to wait before searching for another dropped object
	UPROPERTY(EditAnyWhere)
	float waitTimeToSearchAgain;

	//Bp will find the closest actor and send it so we can document it
	UFUNCTION(BlueprintCallable)
	void ExecuteDocumentationFromBP(AActor* sphere);

	void ExecuteInstruction(ABaseRobot* robot) final;

	bool IsComplete() final;

	private:

	//Helper function to find the clossest dropped object
	AActor* FindClosestDroppedObject();

	//Find the actors that are currently on screen
	void FindActorsInView(TArray<AActor*>& onScreenActors);

	//Save the actors found on screen to a file
	void SaveActorsToFile(TArray<AActor*>& onScreenActors);

	ABaseRobot* callingRobot;
};
