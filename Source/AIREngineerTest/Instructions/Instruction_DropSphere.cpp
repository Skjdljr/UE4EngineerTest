// Fill out your copyright notice in the Description page of Project Settings.


#include "Instruction_DropSphere.h"

void UInstruction_DropSphere::ExecuteInstruction(ABaseRobot* robot)
{
    if (robot != nullptr)
    {
        //auto curTransform = robot->GetActorTransform();
        //const FVector offset(-150,0,0);
        
        GetWorld()->SpawnActor<AActor>(ActorToSpawn);

        isComplete = true;

        if (showDebugMessages)
        {
            auto robotName = robot->GetRobotName().ToString();

            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s Executed Drop Sphere"), *robotName));
        }
    }
}

bool UInstruction_DropSphere::IsComplete()
{
    return isComplete;
}