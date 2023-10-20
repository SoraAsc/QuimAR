// Fill out your copyright notice in the Description page of Project Settings.


#include "ARBDSubsystem.h"
#include "Blueprint/UserWidget.h"
#include "Components/GridPanel.h"
#include "ElementsSelectionUserWidget.h"

UARBDSubsystem::UARBDSubsystem()
{
	//FLinearColor MyColor(0.5, 0.2, 0.8, 1.0);

	elements.Add(new Element("Aluminio", "Al", 26.98, 13, FLinearColor(0.6627, 0.6627, 0.6627), ElementGroupEnum::METAL));
	elements.Add(new Element("Azufre", "Al", 32.07, 16, FLinearColor(1, 1, 0.6), ElementGroupEnum::NAO_METAL)); // Enxofre = Azufre
	elements.Add(new Element("Bromo", "Br", 79.90, 35, FLinearColor(0.6471, 0.1647, 0.1647), ElementGroupEnum::NAO_METAL));
	elements.Add(new Element("Calcio", "Ca", 40.08, 20, FLinearColor(1, 1, 1), ElementGroupEnum::METAL));
	elements.Add(new Element("Carbono", "C", 12.0107, 6, FLinearColor(0, 0, 0), ElementGroupEnum::NAO_METAL));
	elements.Add(new Element("Cloro", "Cl", 35.453, 17, FLinearColor(0, 1, 0), ElementGroupEnum::NAO_METAL));
	elements.Add(new Element("Cobre", "Cu", 63.55, 29, FLinearColor(0.7843, 0.3922, 0), ElementGroupEnum::METAL));
	elements.Add(new Element("Estanho", "Sn", 118.71, 50, FLinearColor(0.6627, 0.6627, 0.6627), ElementGroupEnum::METAL));
	elements.Add(new Element("Fosforo", "P", 30.97, 15, FLinearColor(1, 1, 0.8784), ElementGroupEnum::NAO_METAL));
	elements.Add(new Element("Fluor", "F", 19.00, 9, FLinearColor(0, 0.50196, 0), ElementGroupEnum::NAO_METAL));
	elements.Add(new Element("Ferro", "Fe", 55.85, 26, FLinearColor(0.5451, 0.2706, 0.0745), ElementGroupEnum::METAL));
	elements.Add(new Element("Hidrogenio", "H", 1.00794, 1, FLinearColor(0, 0.749, 1), ElementGroupEnum::NAO_METAL));
	elements.Add(new Element("Iodo", "I", 126.90, 53, FLinearColor(0.50196, 0, 0.50196), ElementGroupEnum::NAO_METAL));
	elements.Add(new Element("Magnesio", "Mg", 24.31, 12, FLinearColor(0.7529, 0.7529, 0.7529), ElementGroupEnum::METAL));
	elements.Add(new Element("Niquel", "Ni", 58.69, 28, FLinearColor(0.7529, 0.7529, 0.7529), ElementGroupEnum::METAL));
	elements.Add(new Element("Nitrogenio", "N", 14.00674, 7, FLinearColor(0, 0, 0.502), ElementGroupEnum::NAO_METAL));
	elements.Add(new Element("Ouro", "Au", 196.97, 79, FLinearColor(1, 0.8431, 0), ElementGroupEnum::METAL));
	elements.Add(new Element("Oxigenio", "O", 15.9994, 8, FLinearColor(1, 0, 0), ElementGroupEnum::NAO_METAL));
	elements.Add(new Element("Prata", "Ag", 107.87, 47, FLinearColor(0.7529, 0.7529, 0.7529), ElementGroupEnum::METAL));
	elements.Add(new Element("Chumbo", "Pb", 207.2, 82, FLinearColor(0.6627, 0.6627, 0.6627), ElementGroupEnum::METAL));
	elements.Add(new Element("Titanio", "Ti", 47.87, 22, FLinearColor(0.7529, 0.7529, 0.7529), ElementGroupEnum::METAL));
	elements.Add(new Element("Zinco", "Zn", 65.38, 30, FLinearColor(0.6627, 0.6627, 0.6627), ElementGroupEnum::METAL));
	
	//elements.Add(new Element("Sodio", "Na", 22.98976928, 11, FLinearColor(1, 1, 0), ElementGroupEnum::NAO_METAL));
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

Element* UARBDSubsystem::GetElement(int index)
{
	return elements[index];
}

int UARBDSubsystem::ElementArraySize()
{
	return elements.Num();
}
