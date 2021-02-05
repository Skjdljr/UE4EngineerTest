// Fill out your copyright notice in the Description page of Project Settings.


#include "Instruction_DocumentSphere.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>
#include "Core/Public/Misc/FileHelper.h"

UInstruction_DocumentSphere::UInstruction_DocumentSphere(): reasonableDistance(300)
{
}

void UInstruction_DocumentSphere::ExecuteInstruction(ABaseRobot* robot)
{
    if (robot != nullptr)
    {
        //loop through all
        //find closest sphere 
        //set as goal
        //then move toward
        //then document
        
        //Fire event to BP, let it do our dirty work
        robot->FindDroppedObjects(this, reasonableDistance);

        if (showDebugMessages)
        {
            auto robotName = robot->GetRobotName().ToString();
            //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s Executed DocumentSphere actors found on screen %f "), *robotName, onScreenActors.Num()));
        }
    }
}

bool UInstruction_DocumentSphere::IsComplete()
{
    return isComplete;
}

/*
* called from baserobot: when/if it finds the closest sphere
*/
void UInstruction_DocumentSphere::SetClosestSphereFromBP(AActor* sphere, float distance)
{
    if (distance <= reasonableDistance)
    {
        //Request screen shot
        FScreenshotRequest::RequestScreenshot("image", false, true);

        //create the array to store actors 
        TArray<AActor*> onScreenActors;

        //Find all actors in viewport
        FindActorsInView(onScreenActors);

        //save them out
        SaveActorsToFile(onScreenActors);

        //Kill the sphere we just found
        if (sphere != nullptr)
            sphere->SetLifeSpan(0.1f);

        //done
        isComplete = true;
    }
}

/*
* Find all actors that are in screenview
*/
void UInstruction_DocumentSphere::FindActorsInView(TArray<AActor*>& onScreenActors)
{
    auto world = GetWorld();

    if (world != nullptr)
    {
        TArray<AActor*> foundActors;

        //Get all actors in the scene
        UGameplayStatics::GetAllActorsOfClass(world, AActor::StaticClass(), foundActors);

        auto localPC = world->GetFirstPlayerController();
        FVector2D screenRef;

        for (auto actor : foundActors)
        {
            auto onScreen = localPC->ProjectWorldLocationToScreen(actor->GetActorLocation(), screenRef);

            if (onScreen)
            {
                onScreenActors.Add(actor);
            }
        }
    }
}

/*
* Helper function to save the actors passed in to a file
*/
void UInstruction_DocumentSphere::SaveActorsToFile(TArray<AActor*>& onScreenActors)
{
    //Get the screen shot name
    auto screenShotPathAndName = FScreenshotRequest::GetFilename();
    
    //Specify what we want removed from the filename
    auto remove = ".png";
    
    //Remove it
    screenShotPathAndName.RemoveFromEnd(remove);

    //Add our file name and extension
    FString FilePath = FPaths::ConvertRelativePathToFull(screenShotPathAndName + TEXT("_actors.txt"));

    FString FileContent;
    
    //loop through our actors and add to the doc
    for (auto actor : onScreenActors)
    {
        FileContent = FString(actor->GetName()+"\n");
        FFileHelper::SaveStringToFile(FileContent, *FilePath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
        FileContent.Empty();
    }
}

