// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseRobot.h"
#include "AIREngineerTest/RobotInstruction.h"


// Sets default values
ABaseRobot::ABaseRobot():robotName("baseRobot"), curInstruction(nullptr), curInstructionIndex(0)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseRobot::AddInstruction(URobotInstruction* inInstruction)
{
	if (inInstruction != nullptr)
	{
		instructions.Add(inInstruction);
	}
}

void ABaseRobot::AddInstructions(TArray<URobotInstruction*> inInstructions)
{
	for (auto instruction : inInstructions)
	{
		AddInstruction(instruction);
	}
}

// Called every frame
void ABaseRobot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (instructions.Num() > 0)
	{
		if (curInstruction == nullptr)
		{
			//Get our instruction
			curInstruction = instructions[curInstructionIndex];

			//make sure they didn't send us a null instruction
			if (curInstruction != nullptr)
			{
				//Let our Instruction fire
				curInstruction->ExecuteInstruction(this);
			}
		}
		else if (curInstruction != nullptr && curInstruction->IsComplete())
		{
			curInstruction = nullptr;

			curInstructionIndex++;

			//instead of removing lets let it loop, so the robots keeeeeeep on going
			if (curInstructionIndex >= instructions.Num())
				curInstructionIndex = 0;
		}
	}
}

// Called to bind functionality to input
void ABaseRobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

FName ABaseRobot::GetRobotName()
{
	return robotName;
}

// when a sphere is dropped send a notify event to the grabber so it knows to start seeking