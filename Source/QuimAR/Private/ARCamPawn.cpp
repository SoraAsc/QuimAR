// Fill out your copyright notice in the Description page of Project Settings.


#include "ARCamPawn.h"
#include "ARSessionConfig.h"
#include "ARBlueprintLibrary.h"
#include "Element.h"
#include "ARBDSubsystem.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include <Kismet/KismetRenderingLibrary.h>
#include "Blueprint/UserWidget.h"
//#include <tesseract/baseapi.h>
//#include <leptonica/allheaders.h>
//#include "Engine/TextureRenderTarget2D.h"
//#include "TextureResource.h"


USceneCaptureComponent2D* mainCapture = nullptr;
UTextureRenderTarget2D* RenderTarget = nullptr;

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
	if (elementsSelectGUI)
	{
		elementsSelectGUI->AddToViewport(0);
	}
	UARSessionConfig* ARSessionConfig = UARBlueprintLibrary::GetSessionConfig();
	UARBlueprintLibrary::StartARSession(ARSessionConfig);	

	mainCapture = FindComponentByClass<USceneCaptureComponent2D>();
	mainCapture->bCaptureEveryFrame = false;
	mainCapture->bAlwaysPersistRenderingState = true;
	mainCapture->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;

	mainCapture->TextureTarget = UKismetRenderingLibrary::CreateRenderTarget2D(this, 512, 512, ETextureRenderTargetFormat::RTF_RGBA16f);
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

void AARCamPawn::GetGameImage()
{
	mainCapture->CaptureScene();
	RenderTarget = mainCapture->TextureTarget;

	if (RenderTarget)
	{
		FTextureRenderTargetResource* RTResource = RenderTarget->GameThread_GetRenderTargetResource();
		if (RTResource)
		{
			TArray<FColor> Pixels;
			RTResource->ReadPixels(Pixels);

			FString Filename = FString("12YourScreenshotGame.png");
			FString FilePath = FPaths::ScreenShotDir() + TEXT("/") + Filename;
			FFileHelper::CreateBitmap(*FilePath, RTResource->GetSizeX(), RTResource->GetSizeY(), Pixels.GetData());
			UE_LOG(LogTemp, Warning, TEXT("Screenshot saved to %s"), *FilePath);
		}
		//tesseract::TessBaseAPI *tess = new tesseract::TessBaseAPI();
		//tess->Init(NULL, "eng");
		//if (tess.Init(nullptr, "eng", tesseract::OEM_DEFAULT) != 0)
		//	return;

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

