// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ARTrackable.h"
#include "Element.h"
#include "ElementHolderTrackedGeometry.generated.h"

/**
 * 
 */
UCLASS()
class QUIMAR_API UElementHolderTrackedGeometry : public UARTrackedGeometry
{
	GENERATED_BODY()

public:
	TArray<AElement> elements;
	
};
