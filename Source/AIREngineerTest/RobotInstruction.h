// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Robots/BaseRobot.h"
#include "RobotInstruction.generated.h"

/*Base instruction - Use EditInLineNew so it can be created in widget, also set it to instanced so we can change/add them in editor*/
UCLASS(EditInlineNew, DefaultToInstanced)
class AIRENGINEERTEST_API URobotInstruction : public UObject
{
	GENERATED_BODY()

public:
	URobotInstruction();	

	UFUNCTION(BlueprintCallable)
	virtual void ExecuteInstruction(ABaseRobot* robot);

	virtual bool IsComplete();

	UPROPERTY(EditAnyWhere)
	bool showDebugMessages;

protected:
	bool isComplete;
};
