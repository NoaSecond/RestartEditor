// Copyright Noa Second 2026. All Rights Reserved.

#include "RestartEditorCommands.h"

#include "RestartEditorStyle.h"

#define LOCTEXT_NAMESPACE "FRestartEditorCommands"

FRestartEditorCommands::FRestartEditorCommands()
	: TCommands<FRestartEditorCommands>(
		TEXT("RestartEditor"),
		NSLOCTEXT("Contexts", "RestartEditor", "Restart Editor"),
		NAME_None,
		FRestartEditorStyle::GetStyleSetName()
	)
{
}

void FRestartEditorCommands::RegisterCommands()
{
	UI_COMMAND(
		RestartEditor,
		"Restart Editor",
		"Restart the Unreal Editor",
		EUserInterfaceActionType::Button,
		FInputChord()
	);
}

#undef LOCTEXT_NAMESPACE