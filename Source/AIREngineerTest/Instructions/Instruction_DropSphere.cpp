// Fill out your copyright notice in the Description page of Project Settings.


#include "Instruction_DropSphere.h"

UInstruction_DropSphere::UInstruction_DropSphere(): spawnOffset(100,0,0)
{
}

void UInstruction_DropSphere::ExecuteInstruction(ABaseRobot* robot)
{
    if (robot != nullptr)
    {
        if (robot->actorToSpawn != nullptr)
        { 
            auto spawnPosition = robot->GetActorTransform().GetLocation() - spawnOffset;

            // Spawn the asset that was chosen for the dropper 
            GetWorld()->SpawnActor<AActor>(robot->actorToSpawn, spawnPosition, robot->GetControlRotation());

            isComplete = true;

            if (showDebugMessages)
            {
                auto robotName = robot->GetRobotName().ToString();

                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s Executed Drop Sphere"), *robotName));
            }
        }
        else
        {
            auto robotName = robot->GetRobotName().ToString();
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s Does not have a actorToSpawn set - nothing will be spawned"), *robotName));

        }

    }
}

bool UInstruction_DropSphere::IsComplete()
{
    return isComplete;
}