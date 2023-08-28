// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Element.generated.h"

UENUM(BlueprintType)
enum class ElementGroupEnum : uint8
{
	NAO_METAL = 0,
	METAL = 1
};

UCLASS()
class QUIMAR_API AElement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FString name;
	FString symbol;
	float massa_atomica;
	int32 numero_atomico;
	FLinearColor elementColor;
	ElementGroupEnum group;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
