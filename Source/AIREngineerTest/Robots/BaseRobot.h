// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseRobot.generated.h"

class URobotInstruction;

UCLASS(Blueprintable)
class AIRENGINEERTEST_API ABaseRobot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseRobot();

	//List of our Robot instructions, make it editable from BP
	UPROPERTY(EditAnywhere, Instanced,  BlueprintReadWrite, meta = (DisplayName = "Array of Robot Instructions"), Category = "Base Robot")
	TArray <URobotInstruction*> instructions;

	//The actor to spawn for any robot
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "The actor to drop from your robot"), Category = "Base Robot")
	TSubclassOf<AActor> actorToSpawn;

	//Helper to add instructions
	void AddInstruction(URobotInstruction* inInstruction);
	void AddInstructions(TArray<URobotInstruction*> inInstructions);

	//Helper function to be created by blueprint
	UFUNCTION(BlueprintImplementableEvent)
	void FindDroppedObjects(UInstruction_DocumentSphere* callingInstruction, float reasonableDistance);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FName GetRobotName();

protected:

	/*
	* Name to use for the robot
	*/
	UPROPERTY(BlueprintReadWrite)
	FName robotName;

	/*
	* The current instruction in the queue
	*/
	URobotInstruction* curInstruction;
};
