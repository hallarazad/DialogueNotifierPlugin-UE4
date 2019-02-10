// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "DialogueNotifierPluginStyle.h"

class FDialogueNotifierPluginCommands : public TCommands<FDialogueNotifierPluginCommands>
{
public:

	FDialogueNotifierPluginCommands()
		: TCommands<FDialogueNotifierPluginCommands>(TEXT("DialogueNotifierPlugin"), NSLOCTEXT("Contexts", "DialogueNotifierPlugin", "DialogueNotifierPlugin Plugin"), NAME_None, FDialogueNotifierPluginStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > CreateNotifiesAction;
	TSharedPtr< FUICommandInfo > DeleteNotifiesAction;
};
