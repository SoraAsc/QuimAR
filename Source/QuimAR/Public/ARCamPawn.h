// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ARBlueprintLibrary.h"
#include "ElementsSelectionUserWidget.h"
#include "ARCamPawn.generated.h"

UCLASS()
class QUIMAR_API AARCamPawn : public APawn
{
	GENERATED_BODY()

protected:
	AActor* spawnedPlane;
	UARTrackedGeometry* geometryOfSpawnedPlane;
	TMap<UARTrackedGeometry*, AActor*> trackedObjectActorMap;
	bool UpdatePlaneCandidate();
	bool CreatePlaneCandidate(UARTrackedGeometry* geo, UARPlaneGeometry* plane);

public:
	// Sets default values for this pawn's properties
	AARCamPawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ElementsCategory")
	TSubclassOf<class AElement> elementToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ElementsCategory")
	TSubclassOf<class AActor> planeToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "ElementsCategory")
	UElementsSelectionUserWidget* elementsSelectGUI;

	UFUNCTION(BlueprintCallable, Category = "ElementsCategory")
	void AddElementOnScene(FString symbol);

	UFUNCTION(BlueprintCallable, Category = "ElementsCategory")
	void GetGameImage();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
