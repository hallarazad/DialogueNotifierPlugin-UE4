// Fill out your copyright notice in the Description page of Project Settings.

#include "DialogueAnimNotify.h"

#include "Components/SkeletalMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundWave.h"
#include "Animation/AnimSequenceBase.h"

UDialogueAnimNotify::UDialogueAnimNotify(const FObjectInitializer & ObjectInitializer) : Super(ObjectInitializer) {

}

UDialogueAnimNotify::UDialogueAnimNotify() {

}


void UDialogueAnimNotify::Print() 
{
}

void UDialogueAnimNotify::Notify(USkeletalMeshComponent * MeshComponent, UAnimSequenceBase * Animation)
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
				soundsPath += "/" + NotifyID;
				soundsPath += ".";
				soundsPath += NotifyID;
				soundsPath += "'";

				FString testPath = FString("SoundWave'/Game/NoEscapezzzzzzzzzzzz/AllSound/DialogueSounds/Anne/A106.A106'");


				USoundWave* audioFile = LoadObject<USoundWave>(NULL, *soundsPath, NULL, LOAD_None);

				if (audioFile) {
					UE_LOG(LogTemp, Warning, TEXT("AudioFile: %s"), *audioFile->GetName());
					ac->Sound = audioFile;
					ac->Play();
				}
				else {
					UE_LOG(LogTemp, Warning, TEXT("Audio file not found!"));
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

FString UDialogueAnimNotify::GetCharacterNameFromAnimation(FString animName) {
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


