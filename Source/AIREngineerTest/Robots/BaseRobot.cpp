// Fill out your copyright notice in the Description page of Project Settings.

#include "AIREngineerTest/RobotInstruction.h"
#include "BaseRobot.h"

// Sets default values
ABaseRobot::ABaseRobot():robotName("baseRobot"), curInstruction(nullptr)
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

	if (instructions.Num() > 0 && curInstruction == nullptr)
	{
		//Get our instruction
		curInstruction = instructions[0];

		//Let our Instruction fire
		curInstruction->ExecuteInstruction(this);

		//Remove from the list 
		instructions.RemoveAt(0);
	}
	else if (curInstruction != nullptr && curInstruction->IsComplete())
	{
		curInstruction = nullptr;
	}

	//if (curInstruction != nullptr )
	//{
	//	//check for complete
	//	if (curInstruction->IsComplete())
	//	{
	//		//delete if complete
	//		curInstruction = nullptr;
	//	}
	//}
	//else 
	//{
	//	//grab an instructions if we have it
	//	if ((instructions.Num() > 0))
	//	{	
	//		//Get our instruction
	//		curInstruction = instructions[0];
	//		//Execute
	//		curInstruction->ExecuteInstruction(this);
	//		//Remove from the list 
	//		instructions.RemoveAt(0);
	//	}
	//}
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

