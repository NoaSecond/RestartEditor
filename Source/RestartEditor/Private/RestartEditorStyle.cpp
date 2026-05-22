// Copyright Noa Second 2026. All Rights Reserved.

#include "RestartEditorStyle.h"

#include "Interfaces/IPluginManager.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateStyleRegistry.h"

TSharedPtr<FSlateStyleSet> FRestartEditorStyle::StyleInstance = nullptr;

void FRestartEditorStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FRestartEditorStyle::Shutdown()
{
	if (StyleInstance.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
		ensure(StyleInstance.IsUnique());
		StyleInstance.Reset();
	}
}

const ISlateStyle& FRestartEditorStyle::Get()
{
	return *StyleInstance;
}

FName FRestartEditorStyle::GetStyleSetName()
{
	return TEXT("RestartEditorStyle");
}

FSlateIcon FRestartEditorStyle::GetIcon(const FString& IconSpecifier)
{
	return FSlateIcon(GetStyleSetName(), FName{*IconSpecifier});
}

TSharedRef<FSlateStyleSet> FRestartEditorStyle::Create()
{
	TSharedRef<FSlateStyleSet> Style = MakeShareable(new FSlateStyleSet(GetStyleSetName()));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin(TEXT("RestartEditor"))->GetBaseDir() / TEXT("Resources"));

	#define IMAGE_BRUSH(RelativePath, ...) FSlateImageBrush(Style->RootToContentDir(RelativePath, TEXT(".png")), __VA_ARGS__)
	#define SVG_BRUSH(RelativePath, ...) FSlateVectorImageBrush(Style->RootToContentDir(RelativePath, TEXT(".svg")), __VA_ARGS__)

	Style->Set(TEXT("RestartEditor.RestartEditor"), new SVG_BRUSH(TEXT("IconRestart"), FVector2D{40.0f, 40.0f}));
	Style->Set(TEXT("RestartEditor.RestartEditor.Small"), new SVG_BRUSH(TEXT("IconRestart"), FVector2D{20.0f, 20.0f}));
	Style->Set(TEXT("RestartEditor.Icon128"), new IMAGE_BRUSH(TEXT("Icon128"), FVector2D{128.0f, 128.0f}));

	#undef IMAGE_BRUSH
	#undef SVG_BRUSH

	return Style;
}