// Fill out your copyright notice in the Description page of Project Settings.


#include "Instruction_Wait.h"

UInstruction_Wait::UInstruction_Wait() : waitTime(5.0f)
{
    isComplete = false;
}

void UInstruction_Wait::ExecuteInstruction(ABaseRobot* robot)
{
    if (robot != nullptr)
    {
        //Set a timer to wait
        GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UInstruction_Wait::TimerElapsed, waitTime, false);

        if (showDebugMessages)
        {
            auto robotName = robot->GetRobotName().ToString();

            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s Started Instruction wait"), *robotName));
        }
    }
}

bool UInstruction_Wait::IsComplete()
{
    return isComplete;
}

void UInstruction_Wait::TimerElapsed()
{
    //clean up our timer
    GetWorld()->GetTimerManager().ClearTimer(timerHandle);

    isComplete = true;

    //debug info
    if (showDebugMessages)
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%f Timer Complete"), waitTime));
}
