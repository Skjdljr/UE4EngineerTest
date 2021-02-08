// Fill out your copyright notice in the Description page of Project Settings.


#include "Instruction_MoveForward.h"

UInstruction_MoveForward::UInstruction_MoveForward() : distanceToMove(200)
{

}

void UInstruction_MoveForward::ExecuteInstruction(ABaseRobot* robot)
{
    Super::ExecuteInstruction(robot);

    isComplete = false;

    if (robot != nullptr)
    {
        auto curLocation = robot->GetActorLocation();
        auto forwardLocation = curLocation + robot->GetActorForwardVector() * distanceToMove;

        auto newLocation = FMath::VInterpTo(robot->GetActorLocation(), forwardLocation, 1, 1);

        FHitResult OutHit;
        robot->SetActorRelativeLocation(newLocation, true, &OutHit, ETeleportType::None);

        //check the resullt to see if we have collided
        if (OutHit.bBlockingHit)
        {
            auto curRot = robot->GetActorRotation();

            //hit something, Spin me right round baby!
            robot->SetActorRotation(FRotator(curRot.Pitch, curRot.Yaw + 180, curRot.Roll) );
        }

        isComplete = true;

        if (showDebugMessages)
        {
            auto robotName = robot->GetRobotName().ToString();
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s Executed Move Forward"), *robotName));
        }
    }
}

bool UInstruction_MoveForward::IsComplete()
{
    return isComplete;
}