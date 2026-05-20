// Copyright Noa Second. All Rights Reserved.

#include "RestartEditor.h"

#include "RestartEditorCommands.h"
#include "RestartEditorStyle.h"

#include "Editor.h"
#include "LevelEditor.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "UnrealEdMisc.h"

#define LOCTEXT_NAMESPACE "FRestartEditorModule"

void FRestartEditorModule::StartupModule()
{
	FRestartEditorStyle::Initialize();
	FRestartEditorCommands::Register();

	CommandList = MakeShared<FUICommandList>();
	CommandList->MapAction(
		FRestartEditorCommands::Get().RestartEditor,
		FExecuteAction::CreateRaw(this, &FRestartEditorModule::HandleRestartEditor)
	);

	UToolMenus::RegisterStartupCallback(
		FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FRestartEditorModule::RegisterMenus)
	);
}

void FRestartEditorModule::ShutdownModule()
{
	UToolMenus::UnRegisterStartupCallback(this);
	UToolMenus::UnregisterOwner(this);

	FRestartEditorCommands::Unregister();
	FRestartEditorStyle::Shutdown();
	CommandList.Reset();
}

void FRestartEditorModule::RegisterMenus()
{
	FToolMenuOwnerScoped OwnerScoped(this);

	UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
	FToolMenuSection& ToolbarSection = ToolbarMenu->FindOrAddSection("Settings");
	FToolMenuEntry& Entry = ToolbarSection.AddEntry(FToolMenuEntry::InitToolBarButton(FRestartEditorCommands::Get().RestartEditor));
	Entry.SetCommandList(CommandList);
}

void FRestartEditorModule::HandleRestartEditor()
{
	const EAppReturnType::Type Result = FMessageDialog::Open(
		EAppMsgType::YesNo,
		LOCTEXT("RestartEditorConfirm", "Restart the Unreal Editor now? Unsaved changes may be lost.")
	);

	if (Result == EAppReturnType::Yes)
	{
		FUnrealEdMisc::Get().RestartEditor(false);
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FRestartEditorModule, RestartEditor)