// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralCubeActor.generated.h"

UCLASS()
class CGGAME_API AProceduralCubeActor : public AActor
{
	GENERATED_BODY()

	//Describes the 3d position of a vertex
	TArray<FVector> Positions;

	//Describes the position to begin sampliling at from a texture from each vertex
	TArray<FVector2D> UVs;

	//Description of the indices that make up each triangle
	// - Every three indices correspondes to a single triangle
	TArray<int32> TrianglesIndices;

	
public:	
	// Sets default values for this actor's properties
	AProceduralCubeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//UE4.X-style
	//UPROPERTY(VisibleAnywhere)
	//class UProceduralMeshComponent* ProceduralMesh;

	//UE5.X-style
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UProceduralMeshComponent> ProceduralMesh;
	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool square;
	bool pentagon;
	bool cube;

};
