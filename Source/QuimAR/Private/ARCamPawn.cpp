// Fill out your copyright notice in the Description page of Project Settings.


#include "ARCamPawn.h"
#include "ARSessionConfig.h"
#include "ARBlueprintLibrary.h"
#include "Element.h"
#include "ARBDSubsystem.h"
#include "Camera/CameraComponent.h"

// Sets default values
AARCamPawn::AARCamPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AARCamPawn::BeginPlay()
{
	Super::BeginPlay();
	UARSessionConfig* ARSessionConfig = UARBlueprintLibrary::GetSessionConfig();
	UARBlueprintLibrary::StartARSession(ARSessionConfig);	
}

void AARCamPawn::AddElementOnScene(FString symbol)
{
	UARBDSubsystem* ARGameInstance = GetGameInstance()->GetSubsystem<UARBDSubsystem>();
	Element* ele = ARGameInstance->GetElement(symbol);
	if (ele != NULL)
	{
		UCameraComponent* Camera = FindComponentByClass<UCameraComponent>();

		FTransform CameraTransform = Camera->GetComponentTransform();
		FVector CameraForward = CameraTransform.GetUnitAxis(EAxis::X);

		FVector SpawnLocation = CameraTransform.GetLocation() + CameraForward * 20;
		FRotator SpawnRotation = FRotationMatrix::MakeFromX(CameraForward).Rotator();

		AElement* element = GetWorld()->SpawnActor<AElement>(elementToSpawn, SpawnLocation, SpawnRotation);
		UMeshComponent* Mesh = element->FindComponentByClass<UMeshComponent>();
		UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Mesh->GetMaterial(0), this);

		if (DynMaterial)
		{
			DynMaterial->SetVectorParameterValue("Param", ele->elementColor); 
			Mesh->SetMaterial(0, DynMaterial);
		}
	}
}

// Called every frame
void AARCamPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TArray<UARTrackedGeometry*> allARGeometries = UARBlueprintLibrary::GetAllGeometries();

	for (UARTrackedGeometry* Geometry : allARGeometries)
	{
		Geometry->DebugDraw(GetWorld(), FLinearColor::Red, 5.0, 0.0);
	}
}

// Called to bind functionality to input
void AARCamPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

