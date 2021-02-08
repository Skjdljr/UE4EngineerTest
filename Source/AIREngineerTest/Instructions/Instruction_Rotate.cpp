// Fill out your copyright notice in the Description page of Project Settings.


#include "Instruction_Rotate.h"

UInstruction_Rotate::UInstruction_Rotate() : rotationAmount(30)
{
}

//called from bp when done rotating
void UInstruction_Rotate::SetComplete(bool complete)
{
    isComplete = complete;
}

void UInstruction_Rotate::ExecuteInstruction(ABaseRobot* robot)
{
    Super::ExecuteInstruction(robot);

    isComplete = false;

    if (robot != nullptr)
    {
        robot->Rotate(rotationAmount, this);

        if (showDebugMessages)
        {
            auto robotName = robot->GetRobotName().ToString();
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s Executed Rotate %f degrees"), *robotName, rotationAmount));
        }
    }
}

bool UInstruction_Rotate::IsComplete()
{
    return isComplete;
}
