// Fill out your copyright notice in the Description page of Project Settings.


#include "Instruction_DropSphere.h"

UInstruction_DropSphere::UInstruction_DropSphere(): callingRobot(nullptr)
{
}

void UInstruction_DropSphere::SetSpawnLocationForDroppables(FVector spawnLocation)
{
    // Spawn the asset that was chosen for the dropper 
    GetWorld()->SpawnActor<AActor>(callingRobot->actorToSpawn, spawnLocation, callingRobot->GetActorRotation());

    isComplete = true;
}

void UInstruction_DropSphere::ExecuteInstruction(ABaseRobot* robot)
{
    Super::ExecuteInstruction(robot);

    isComplete = false;

    if (robot != nullptr)
    {
        callingRobot = robot;
        auto robotName = robot->GetRobotName().ToString();

        if (robot->actorToSpawn != nullptr)
        {
            //bp event to get the span location, they will call back with SetSpawnLocationForDroppables
            robot->GetSpawnLocationForObjects(this);

            if (showDebugMessages)
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s Executed Drop Sphere"), *robotName));
            }
        }
        else
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s Does not have a actorToSpawn set - nothing will be spawned"), *robotName));
        }
    }
}

bool UInstruction_DropSphere::IsComplete()
{
    return isComplete;
}