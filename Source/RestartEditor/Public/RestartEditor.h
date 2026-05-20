// Copyright Noa Second. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FUICommandList;

class FRestartEditorModule final : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual bool SupportsDynamicReloading()
	{
		return false;
	}

	virtual bool IsGameModule() const override
	{
		return false;
	}

private:
	void RegisterMenus();
	void HandleRestartEditor();

	TSharedPtr<FUICommandList> CommandList;
};