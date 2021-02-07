// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseRobot.generated.h"

class URobotInstruction;

UENUM()
enum RobotType
{
	GRABBER     UMETA(DisplayName = "Grabber Robot"),
	DROPPER      UMETA(DisplayName = "Dropper Robot")
};

UCLASS(Blueprintable)
class AIRENGINEERTEST_API ABaseRobot : public APawn
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Robot")
	TEnumAsByte<RobotType> robotType;

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

	//Bp event to seek out the object given
	UFUNCTION(BlueprintImplementableEvent)
	void SeekObject(AActor* object, UInstruction_DocumentSphere* callingInstruction);

	//Bp event to seek out the object given
	UFUNCTION(BlueprintImplementableEvent)
	void MoveForward(float distanceToMove);

	//Bp event to seek out the object given
	UFUNCTION(BlueprintImplementableEvent)
	void Rotate(float rotationAmount, UInstruction_Rotate* instruction);

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

private:
	//the index into the array of instructions
	int curInstructionIndex;
};
