// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PJ_Exo_Cynthia : ModuleRules
{
	public PJ_Exo_Cynthia(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"PJ_Exo_Cynthia",
			"PJ_Exo_Cynthia/Variant_Horror",
			"PJ_Exo_Cynthia/Variant_Horror/UI",
			"PJ_Exo_Cynthia/Variant_Shooter",
			"PJ_Exo_Cynthia/Variant_Shooter/AI",
			"PJ_Exo_Cynthia/Variant_Shooter/UI",
			"PJ_Exo_Cynthia/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
