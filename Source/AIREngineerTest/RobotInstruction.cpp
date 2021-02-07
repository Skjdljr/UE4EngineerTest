// Copyright Epic Games, Inc. All Rights Reserved.

#include "RobotInstruction.h"

URobotInstruction::URobotInstruction() : showDebugMessages(false), isComplete(false)
{
	
}

void URobotInstruction::ExecuteInstruction(ABaseRobot* robot)
{
	//no op
}

bool URobotInstruction::IsComplete()
{
	return isComplete;
}

//Trick to force an instruction to complete - this is to be used mainly for navigation/being stuck
bool URobotInstruction::AbortInstruction()
{
	//get out of an instruction for what ever reason.
	return isComplete = true;
}
