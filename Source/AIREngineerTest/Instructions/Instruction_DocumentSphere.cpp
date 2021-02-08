// Fill out your copyright notice in the Description page of Project Settings.


#include "Instruction_DocumentSphere.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>
#include "Core/Public/Misc/FileHelper.h"

UInstruction_DocumentSphere::UInstruction_DocumentSphere()
{
}

void UInstruction_DocumentSphere::ExecuteInstruction(ABaseRobot* robot)
{
    Super::ExecuteInstruction(robot);

    isComplete = false;

    if (robot != nullptr)
    {
        callingRobot = robot;

        //Find closest dropped object
        auto closestObject = FindClosestDroppedObject();

        //an object has not spawned yet
        if (closestObject != nullptr)
        {
            //Fire event to BP, let it do our dirty work
            callingRobot->SeekObject(closestObject, this);
        }
        else
        {
            //so instead of sitting in this instruction forever, just set to true.
            isComplete = true;
        }
    }
}

bool UInstruction_DocumentSphere::IsComplete()
{
    return isComplete;
}

/*
* called from baserobot: when it finds the closest sphere
*/
void UInstruction_DocumentSphere::ExecuteDocumentationFromBP(AActor* sphere)
{
    //Request screen shot
    FScreenshotRequest::RequestScreenshot("image", false, true);

    //Kill the sphere we found
    if (sphere != nullptr)
        sphere->SetLifeSpan(0.1f);

    //create the array to store actors 
    TArray<AActor*> onScreenActors;

    //Find all actors in viewport
    FindActorsInView(onScreenActors);

    //save them out
    SaveActorsToFile(onScreenActors);

    //done
    isComplete = true;

    if (showDebugMessages)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s Executed DocumentSphere actors found on screen %f "), *callingRobot->GetRobotName().ToString(), onScreenActors.Num()));
    }
}

//find closest object of the type set in bp
AActor* UInstruction_DocumentSphere::FindClosestDroppedObject()
{
    auto world = GetWorld();

    AActor* closestObject = nullptr;

    if (world != nullptr)
    {
        TArray<AActor*> foundActors;

        //find all of the dropped objects
        UGameplayStatics::GetAllActorsOfClass(world, callingRobot->actorToSpawn.Get(), foundActors);

        float closestDistance = 0.0f;
        
        for (auto object : foundActors)
        {
            //ue4 why you name the length size.... 
            float vectorLength = (object->GetActorLocation() - callingRobot->GetActorLocation()).Size();

            //first time: its the closest
            if (closestObject == nullptr)
            {
                closestDistance = vectorLength;
                closestObject = object;
            }
            else
            {
                // store the closest
                if (vectorLength < closestDistance)
                {
                    closestDistance = vectorLength;
                    closestObject = object;
                }
            }
        }
    }

    return closestObject;
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

            //see if they are on screen
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

