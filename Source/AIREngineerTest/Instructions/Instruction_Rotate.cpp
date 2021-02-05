// Fill out your copyright notice in the Description page of Project Settings.


#include "Instruction_Rotate.h"

UInstruction_Rotate::UInstruction_Rotate() : rotationAmount(90)
{
}

void UInstruction_Rotate::ExecuteInstruction(ABaseRobot* robot)
{
    if (robot != nullptr)
    {
        auto curRotation = robot->GetActorRotation();
        robot->AddActorLocalRotation(curRotation.Add(0, rotationAmount, 0));
        isComplete = true;

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
