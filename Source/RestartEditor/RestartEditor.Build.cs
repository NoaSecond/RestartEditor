using UnrealBuildTool;

public class RestartEditor : ModuleRules
{
	public RestartEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"CoreUObject",
				"Engine",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"Slate",
				"SlateCore",
				"ToolMenus",
				"UnrealEd",
				"Projects",
				"LevelEditor",
			}
		);
	}
}