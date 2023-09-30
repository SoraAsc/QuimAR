// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "AddElementButton.generated.h"

/**
 * 
 */
UCLASS()
class QUIMAR_API UAddElementButton : public UButton
{
	GENERATED_BODY()

public:
	FString elementSymbol;
	UFUNCTION()
	void ConfigureButton();
	UFUNCTION()
	void OnClick();
	
};
