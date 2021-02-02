// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseRobot.h"

// Sets default values
ABaseRobot::ABaseRobot()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseRobot::AddInstruction(URobotInstruction* instruction)
{
	if (instruction != nullptr)
	{
		Instructions.Add(instruction);
	}
}

void ABaseRobot::AddInstruction(TArray<URobotInstruction*> instructions)
{
	for (auto instruction : instructions)
	{
		AddInstruction(instruction);
	}
}

// Called when the game starts or when spawned
void ABaseRobot::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseRobot::ExecuteInstruction()
{

}

// Called every frame
void ABaseRobot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseRobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

