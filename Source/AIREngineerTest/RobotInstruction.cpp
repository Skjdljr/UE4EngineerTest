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