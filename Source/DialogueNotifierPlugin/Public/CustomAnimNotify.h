// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "CustomAnimNotify.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGUENOTIFIERPLUGIN_API UCustomAnimNotify : public UAnimNotify
{
	GENERATED_BODY()

public:

	UCustomAnimNotify(const FObjectInitializer & ObjectInitializer);
	UCustomAnimNotify();
	


	UPROPERTY(EditAnywhere, Category = "Custom Notify")
	FString NotifyID;

	void OnAnimNotifyCreatedInEditor(FAnimNotifyEvent &ContainingAnimNotify) override;

	void Notify(USkeletalMeshComponent * MeshComponent, UAnimSequenceBase * Animation) override;

	bool Received_Notify(USkeletalMeshComponent * MeshComponent, UAnimSequenceBase * Animation);

	static FString GetCharacterNameFromAnimation(FString animName);
	static FString GetSceneNameFromAnimation(FString animName);

};
