// Fill out your copyright notice in the Description page of Project Settings.


#include "AddElementButton.h"
#include "ARCamPawn.h"

void UAddElementButton::ConfigureButton()
{
	OnClicked.AddDynamic(this, &UAddElementButton::OnClick);
}

void UAddElementButton::OnClick()
{
	AARCamPawn* pawn = GetWorld()->GetFirstPlayerController()->GetPawn<AARCamPawn>();
	if (pawn)
	{
		pawn->AddElementOnScene(elementSymbol);
	}
}
