// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomAnimNotify.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundWave.h"
#include "Animation/AnimSequenceBase.h"

UCustomAnimNotify::UCustomAnimNotify(const FObjectInitializer & ObjectInitializer) : Super(ObjectInitializer) {
	
}

UCustomAnimNotify::UCustomAnimNotify() {

}

void UCustomAnimNotify::OnAnimNotifyCreatedInEditor(FAnimNotifyEvent & ContainingAnimNotify)
{
	UE_LOG(LogTemp, Warning, TEXT("Created Notify! %s"), *NotifyID);
}

void UCustomAnimNotify::Notify(USkeletalMeshComponent * MeshComponent, UAnimSequenceBase * Animation)
{

	UE_LOG(LogTemp, Warning, TEXT("Notifier: %s"), *NotifyID);

	if (MeshComponent->GetWorld()) {
		switch (MeshComponent->GetWorld()->WorldType) {
		

		case EWorldType::GamePreview:
		case EWorldType::Game:
		case EWorldType::PIE:
		
			{
				UE_LOG(LogTemp, Warning, TEXT("Notifier: %s"), *NotifyID);

				UAudioComponent* ac = Cast<UAudioComponent>(MeshComponent->GetOwner()->FindComponentByClass(UAudioComponent::StaticClass()));
				if (ac) {

					FString soundsPath = FString("SoundWave'/Game/");
					//soundsPath += GetCharacterNameFromAnimation(Animation->GetName());
					soundsPath += "NoEscapezzzzzzzzzzzz/AllSound/DialogueSounds/";
					soundsPath += GetCharacterNameFromAnimation(Animation->GetName());
					soundsPath += "/" + NotifyID + "." + NotifyID;
					soundsPath += "'";

					
					
					USoundWave* audioFile = LoadObject<USoundWave>(NULL, *soundsPath, NULL, LOAD_None);

					if (audioFile) {
						UE_LOG(LogTemp, Warning, TEXT("AudioFile: %s"), *audioFile->GetName());
						ac->Sound = audioFile;
						ac->Play();
					}
				}
			}
			break;


		case EWorldType::Editor:
			UE_LOG(LogTemp, Warning, TEXT("Editor mode!"));
			break;

		case EWorldType::EditorPreview:
			UE_LOG(LogTemp, Warning, TEXT("NotifyID: %s, EditorPreview mode!"), *NotifyID);
			break;

		default:
			UE_LOG(LogTemp, Warning, TEXT("Default mode!"));
			break;
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("World not found!"));
	}

	
}

bool UCustomAnimNotify::Received_Notify(USkeletalMeshComponent * MeshComponent, UAnimSequenceBase * Animation)
{

	UE_LOG(LogTemp, Warning, TEXT("Notifier: %s"), *NotifyID);

	return true;
}

FString UCustomAnimNotify::GetCharacterNameFromAnimation(FString animName) {
	if (animName.Contains("Anne") || animName.Contains("AN")) {
		return "Anne";
	}
	else if (animName.Contains("James") || animName.Contains("JM") || animName.Contains("james")) {
		return "James";
	}
	else if (animName.Contains("John") || animName.Contains("JB")) {
		return "John";
	}
	else if (animName.Contains("KR") || animName.Contains("kr")) {
		return "Kerrie";
	}
	else if (animName.Contains("Butler") || animName.Contains("Buttler") || animName.Contains("BT") || animName.Contains("butler") || animName.Contains("bt")) {
		return "Butler";
	}
	else if (animName.Contains("KM") || animName.Contains("Mayer") || animName.Contains("mayer")) {
		return "Mayer";
	}
	else if (animName.Contains("Colt") || animName.Contains("CB")) {
		return "Colt";
	}
	else {
		return "";
	}
}

FString UCustomAnimNotify::GetSceneNameFromAnimation(FString animName) {
	if (animName.Contains("_AP_")) {
		return "AP";
	}
	else if (animName.Contains("_MS_")) {
		return "MS";
	}
	else if (animName.Contains("_UC_")) {
		return "UC";
	}
	else if (animName.Contains("_UO_")) {
		return "UO";
	}
	else if (animName.Contains("_M_")) {
		return "M";
	}
	else {
		return "";
	}
}

