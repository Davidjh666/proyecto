// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Proyecto : ModuleRules
{
	public Proyecto(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
