#include "CustomNotifierModule.h"
 
DEFINE_LOG_CATEGORY(CustomNotifierModule);
 
#define LOCTEXT_NAMESPACE "FCustomNotifierModule"
 
void FCustomNotifierModule::StartupModule()
{
	UE_LOG(CustomNotifierModule, Warning, TEXT("Notifier module has started!"));
}
 
void FCustomNotifierModule::ShutdownModule()
{
	UE_LOG(CustomNotifierModule, Warning, TEXT("Notifier module has shut down"));
}
 
#undef LOCTEXT_NAMESPACE
 
IMPLEMENT_MODULE(FCustomNotifierModule, CustomNotifierModule)