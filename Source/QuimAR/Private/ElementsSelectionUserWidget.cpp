// Fill out your copyright notice in the Description page of Project Settings.


#include "ElementsSelectionUserWidget.h"
#include "ARBDSubsystem.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "ARCamPawn.h"
#include "AddElementButton.h"

void UElementsSelectionUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	LoadAllEmentsOnGUI();
}

void UElementsSelectionUserWidget::LoadAllEmentsOnGUI()
{
	UARBDSubsystem* ARGameInstance = GetGameInstance()->GetSubsystem<UARBDSubsystem>();
	if (grid)
	{
		int n = ARGameInstance->ElementArraySize();
		for (int i = 0; i < n; i++)
		{
			Element* ele = ARGameInstance->GetElement(i);
			UUserWidget* widget = CreateWidget(this, elementsToShowOnGUI);

			UWidget* genericText = widget->GetWidgetFromName(TEXT("elementName"));
			Cast<UTextBlock>(genericText)->SetText(FText::FromString(ele->name));

			UAddElementButton* btn = Cast<UAddElementButton>(widget->GetWidgetFromName(TEXT("btnPlaceElement")));

			btn->OnClicked.AddDynamic(this, &UElementsSelectionUserWidget::HandleElementClick);

			widget->SetPadding(FMargin(20.0f, 20.0f, 0, 0));
			grid->AddChildToGrid(widget, 0, i);
		}
	}
}

void UElementsSelectionUserWidget::HandleElementClick()
{
	AARCamPawn* pawn = GetWorld()->GetFirstPlayerController()->GetPawn<AARCamPawn>();
	if (pawn)
	{
		pawn->AddElementOnScene("Cl");
	}
}
