// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class CustomNotifierModule : ModuleRules
{
	public CustomNotifierModule(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
        
	}
}
