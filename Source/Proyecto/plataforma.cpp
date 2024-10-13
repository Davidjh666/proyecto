// Fill out your copyright notice in the Description page of Project Settings.


#include "plataforma.h"

// Sets default values
Aplataforma::Aplataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	MeshComponentePlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	MeshComponentePlataforma->SetStaticMesh(MeshAsset.Object);
	RootComponent = MeshComponentePlataforma;

}

// Called when the game starts or when spawned
void Aplataforma::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aplataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

