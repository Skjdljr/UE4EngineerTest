// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Robots/BaseRobot.h"
#include "RobotInstruction.generated.h"

/*Base instruction - Use EditInLineNew so it can be created in widget, also set it to instanced so we can change/add them in editor
* also set abstract so someone in BP cannot try and make one of these, as it will be NO-OP
*/
UCLASS(EditInlineNew, DefaultToInstanced, Abstract)
class AIRENGINEERTEST_API URobotInstruction : public UObject
{
	GENERATED_BODY()

public:
	URobotInstruction();	

	UFUNCTION(BlueprintCallable)
	virtual void ExecuteInstruction(ABaseRobot* robot);

	virtual bool IsComplete();

	UFUNCTION(BlueprintCallable)
	virtual bool AbortInstruction();

	UPROPERTY(EditAnyWhere)
	bool showDebugMessages;

protected:
	bool isComplete;
};
