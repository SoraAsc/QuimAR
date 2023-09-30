// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/GridPanel.h"
#include "ElementsSelectionUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class QUIMAR_API UElementsSelectionUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UPROPERTY(meta = (BindWidget))
	UGridPanel* grid;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> elementsToShowOnGUI;

	void LoadAllEmentsOnGUI();

protected:
	virtual void NativeConstruct() override;
	
};
