// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "plataforma.generated.h"

UCLASS()
class PROYECTO_API Aplataforma : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aplataforma();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UStaticMeshComponent* MeshComponentePlataforma;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
