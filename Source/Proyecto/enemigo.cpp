// Fill out your copyright notice in the Description page of Project Settings.


#include "enemigo.h"

// Sets default values
Aenemigo::Aenemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	MeshComponenteenemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	MeshComponenteenemigo->SetStaticMesh(MeshAsset.Object);
	RootComponent = MeshComponenteenemigo;
}

// Called when the game starts or when spawned
void Aenemigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aenemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

