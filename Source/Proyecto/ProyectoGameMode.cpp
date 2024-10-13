// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProyectoGameMode.h"
#include "ProyectoCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "plataforma.h"
#include "enemigo.h"

AProyectoGameMode::AProyectoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
}

void AProyectoGameMode::BeginPlay()
{
	Super::BeginPlay();

	FTransform SpawnLocation;
	FTransform SpawnLocation2;
	SpawnLocation.SetLocation(FVector(1206.6f, 500.0f, 660.0f));
	SpawnLocation.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
	SpawnLocation.SetScale3D(FVector(1.0f, 10.0f, 1.0f));
	GetWorld()->SpawnActor<Aplataforma>(Aplataforma::StaticClass(), SpawnLocation);

	float MinX = -59.0f;
	float MaxX = 2100.0f;
	float MinY = -1719.0f;
	float MaxY = 1540.0f;
	float MinZ = 276.0f;
	float MaxZ = 1256.0f;




	for (int32 i = 0; i < 3; ++i)
	{
		FVector RandomSpawnLocation;
		RandomSpawnLocation.X = FMath::RandRange(MinX, MaxX);
		RandomSpawnLocation.Y = FMath::RandRange(MinY, MaxY);
		RandomSpawnLocation.Z = FMath::RandRange(MinZ, MaxZ);

		FRotator SpawnRotation = FRotator::ZeroRotator;
		FActorSpawnParameters SpawnParams;

		GetWorld()->SpawnActor<Aenemigo>(Aenemigo::StaticClass(), RandomSpawnLocation, SpawnRotation, SpawnParams);

		// Registro del spawn del enemigo
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Enemigo %d se spawneo en la coordenada X: %f, Y: %f, Z: %f"), i + 1, RandomSpawnLocation.X, RandomSpawnLocation.Y, RandomSpawnLocation.Z));
	}
};




