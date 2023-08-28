// Fill out your copyright notice in the Description page of Project Settings.


#include "Element.h"

// Sets default values
AElement::AElement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AElement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AElement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

