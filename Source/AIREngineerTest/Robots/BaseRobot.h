// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AIREngineerTest/RobotInstruction.h"
#include "BaseRobot.generated.h"

UCLASS()
class AIRENGINEERTEST_API ABaseRobot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseRobot();

	void AddInstruction(URobotInstruction* instruction);
	void AddInstruction(TArray<URobotInstruction*> instructions);

protected:
	
	UPROPERTY()
	TArray <URobotInstruction*> Instructions;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void ExecuteInstruction();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
