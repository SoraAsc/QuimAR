// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Element.h"
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ARBDSubsystem.generated.h"

class Element
{
	public:
		FString name;
		FString symbol;
		float massa_atomica;
		int32 numero_atomico;
		FLinearColor elementColor;
		ElementGroupEnum group;
		Element(FString name, FString symbol, float massa_atomica, int32 numero_atomico, 
			FLinearColor elementColor, ElementGroupEnum group)
		{
			this->name = name;
			this->symbol = symbol;
			this->massa_atomica = massa_atomica;
			this->numero_atomico = numero_atomico;
			this->elementColor = elementColor;
			this->group = group;
		};
};

/**
 * 
 */
UCLASS()
class QUIMAR_API UARBDSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	public:
		UARBDSubsystem();
		Element* GetElement(FString symbol);
		Element* GetElement(int index);
		int ElementArraySize();

	protected:
		TArray<Element*> elements;
	
};
