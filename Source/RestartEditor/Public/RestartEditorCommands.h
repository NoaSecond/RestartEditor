// Copyright Noa Second. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"

class FRestartEditorCommands final : public TCommands<FRestartEditorCommands>
{
public:
	FRestartEditorCommands();
	virtual void RegisterCommands() override;

	TSharedPtr<FUICommandInfo> RestartEditor;
};