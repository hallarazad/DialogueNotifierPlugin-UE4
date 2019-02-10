// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "DialogueAnimNotify.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMNOTIFIERMODULE_API UDialogueAnimNotify : public UAnimNotify
{
	GENERATED_BODY() 


public:

	UDialogueAnimNotify(const FObjectInitializer & ObjectInitializer);
	UDialogueAnimNotify();

	UPROPERTY(VisibleAnywhere, Category = "NotifyID")
	FString NotifyID;

	void Print();

	void Notify(USkeletalMeshComponent * MeshComponent, UAnimSequenceBase * Animation) override;

	FString GetCharacterNameFromAnimation(FString animName);
	
};
