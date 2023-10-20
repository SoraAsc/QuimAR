// Fill out your copyright notice in the Description page of Project Settings.


#include "ARCamPawn.h"
#include "ARSessionConfig.h"
#include "ARBlueprintLibrary.h"
#include "Element.h"
#include "ARBDSubsystem.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include <Kismet/KismetRenderingLibrary.h>
#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>
#include "Blueprint/UserWidget.h"


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


bool AARCamPawn::UpdatePlaneCandidate()
{
	int32 viX, viY;
	GetWorld()->GetFirstPlayerController()->GetViewportSize(viX, viY);
	FVector2D screenPos(viX / 2.0f, viY / 2.0f);
	TArray<FARTraceResult> trackedResults = UARBlueprintLibrary::LineTraceTrackedObjects(screenPos, false, false, true, true);
	if (!trackedResults.IsEmpty())
	{
		FARTraceResult trackedObject = trackedResults[0];

		return CreatePlaneCandidate(trackedObject.GetTrackedGeometry(), Cast<UARPlaneGeometry>(trackedObject.GetTrackedGeometry()));
	}
	return false;
}

bool AARCamPawn::CreatePlaneCandidate(UARTrackedGeometry* geo, UARPlaneGeometry* plane)
{
	if(spawnedPlane != nullptr && spawnedPlane->IsValidLowLevel())
		GetWorld()->DestroyActor(spawnedPlane);

	spawnedPlane = GetWorld()->SpawnActor(planeToSpawn);
	geometryOfSpawnedPlane = geo;
	spawnedPlane->SetActorLocation(plane->GetLocalToWorldTransform().GetLocation());

	FVector planeForward = plane->GetLocalToWorldTransform().GetRotation().GetForwardVector();

	spawnedPlane->SetActorRotation(planeForward.Rotation());
	
	spawnedPlane->SetActorScale3D((plane->GetExtent() / 80.0f) * FVector(1,1,0) + FVector::UpVector);
	return true;
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

		//FVector SpawnLocationCamera = CameraTransform.GetLocation() + CameraForward * 20;
		FRotator SpawnRotation = FRotationMatrix::MakeFromX(CameraForward).Rotator();

		if (spawnedPlane)
		{
			FVector SpawnLocationPlane = spawnedPlane->GetActorLocation();
			//FVector cameraToPlane = SpawnLocationPlane - SpawnLocationCamera;
			//cameraToPlane.Normalize();
			AElement* element = GetWorld()->SpawnActor<AElement>(elementToSpawn, SpawnLocationPlane, SpawnRotation);
			trackedObjectActorMap.Add(geometryOfSpawnedPlane, element);
			UMeshComponent* Mesh = element->FindComponentByClass<UMeshComponent>();
			UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Mesh->GetMaterial(0), this);

			if (DynMaterial)
			{
				DynMaterial->SetVectorParameterValue("Param", ele->elementColor);
				Mesh->SetMaterial(0, DynMaterial);
			}
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

			tesseract::TessBaseAPI* api = new tesseract::TessBaseAPI();
			//if (api->Init("F:\\Projects\\Unreal Projects\\QuimAR\\Source\\QuimAR\\OCR\\tessdata", "eng"))
			if (api->Init(NULL, "eng"))
			{
				fprintf(stderr, "");
			}
			// Open input image with leptonica library
			//Pix* image = pixRead("/usr/src/tesseract/testing/phototest.tif");
			//Pix* image = pixRead("F:\\Projects\\Unreal Projects\\QuimAR\\Saved\\Screenshots\\WindowsEditor\\OCoracaoDoHomem.png");
			char* result = TCHAR_TO_ANSI(*FilePath);
			Pix* image = pixRead(result);
			api->SetImage(image);
			// Get OCR result
			char* outText = api->GetUTF8Text();
			//printf("OCR output:\n%s", outText);

			// Destroy used object and release memory
			api->End();
			//delete api;
			FString recognizedText = FString(outText);
			UE_LOG(LogTemp, Warning, TEXT("OCR output:\n%s"), *recognizedText);
			//delete[] outText;
			pixDestroy(&image);
		}
	}
}

// Called every frame
void AARCamPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	bool planeExist = UpdatePlaneCandidate();
	if (!elementsSelectGUI->GetUIActivedVisibilityState() && planeExist && !elementsSelectGUI->GetPlaceButtonVisibilityState())
		elementsSelectGUI->ShowPlaceButton();
	else if(elementsSelectGUI->GetPlaceButtonVisibilityState() && !planeExist)
		elementsSelectGUI->HiddenPlaceButton();

	TArray<UARTrackedGeometry*> allARGeometries = UARBlueprintLibrary::GetAllGeometries();
	for (UARTrackedGeometry* Geometry : allARGeometries)
	{
		AActor* trackedElement = trackedObjectActorMap.FindRef(Geometry);
		if (trackedElement)
		{
			trackedElement->SetActorLocation(Geometry->GetLocalToWorldTransform().GetLocation());
			trackedElement->SetActorRotation(Geometry->GetLocalToWorldTransform().GetRotation());
		}
		Geometry->DebugDraw(GetWorld(), FLinearColor::Red, 5.0, 0.0);
	}
	//UpdatePlaneCandidate();

	//trackedObject.GetTrackedGeometry();

	//TArray<UARTrackedGeometry*> allARGeometries = UARBlueprintLibrary::GetAllGeometries();

	//for (UARTrackedGeometry* Geometry : allARGeometries)
	//{
	//	Geometry->DebugDraw(GetWorld(), FLinearColor::Red, 5.0, 0.0);
	//}
}

// Called to bind functionality to input
void AARCamPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

