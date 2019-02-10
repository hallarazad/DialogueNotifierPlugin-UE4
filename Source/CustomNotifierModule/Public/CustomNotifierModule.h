#pragma once

#include "ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(CustomNotifierModule, All, All);

class FCustomNotifierModule : public IModuleInterface
{
	public:

	virtual void StartupModule() override;

	virtual void ShutdownModule() override;

};