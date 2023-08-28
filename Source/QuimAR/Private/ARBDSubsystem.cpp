// Fill out your copyright notice in the Description page of Project Settings.


#include "ARBDSubsystem.h"

UARBDSubsystem::UARBDSubsystem()
{
	FLinearColor MyColor(0.5, 0.2, 0.8, 1.0);

	elements.Add(new Element("Oxigenio", "O", 15.9994, 8, FLinearColor(1, 0, 0), ElementGroupEnum::NAO_METAL));
	elements.Add(new Element("Hidrogenio", "H", 1.00794, 1, FLinearColor(0, 0.75, 1), ElementGroupEnum::NAO_METAL));
	elements.Add(new Element("Carbono", "C", 12.0107, 6, FLinearColor(0, 0, 0), ElementGroupEnum::NAO_METAL));
	elements.Add(new Element("Nitrogenio", "N", 14.00674, 7, FLinearColor(0, 0, 0.502), ElementGroupEnum::NAO_METAL));
	elements.Add(new Element("Sodio", "Na", 22.98976928, 11, FLinearColor(1, 1, 0), ElementGroupEnum::NAO_METAL));
	elements.Add(new Element("Cloro", "Cl", 35.453, 17, FLinearColor(0, 0.502, 0), ElementGroupEnum::METAL));
}

Element* UARBDSubsystem::GetElement(FString symbol)
{
	for (int i = 0; i < elements.Num(); i++)
	{
		if (elements[i]->symbol == symbol)
			return elements[i];
	}
	return NULL;
}