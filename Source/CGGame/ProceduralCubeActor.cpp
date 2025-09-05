// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralCubeActor.h"
#include "ProceduralMeshComponent.h"
#include "DrawDebugHelpers.h" // for DrawDebugMesh
#include "InputAction.h"

// Sets default values
AProceduralCubeActor::AProceduralCubeActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initalize my components
	//Make sure that the root component is assigned too
	RootComponent = ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>("ProceduralMesh");
}

// Called when the game starts or when spawned
void AProceduralCubeActor::BeginPlay()
{
	Super::BeginPlay();

	//square = true;
	//pentagon = true;
	cube = true;

	//Square
#pragma region

	if (square == true)
	{
		Positions.Add(FVector(0, 0, 0)); //1st vert
		Positions.Add(FVector(0, 50, 0)); //2nd vert
		Positions.Add(FVector(0, 50, 50)); //3rd vert
		Positions.Add(FVector(0, 0, 50)); //4th vert

		TrianglesIndices.Add(0);
		TrianglesIndices.Add(1);
		TrianglesIndices.Add(2);

		TrianglesIndices.Add(2);
		TrianglesIndices.Add(3);
		TrianglesIndices.Add(0);
	}

#pragma endregion

	//Pentagon
#pragma region

	if (pentagon == true)
	{
		Positions.Add(FVector(0, 0, 0)); //1st vert / center (0)

		Positions.Add(FVector(0, -29.39, -40.45)); //2nd vert
		Positions.Add(FVector(0, 29.39, -40.45)); //3rd vert

		Positions.Add(FVector(0, 47.55, 15.45)); //4th vert
		Positions.Add(FVector(0, 0, 50)); //5th vert / Top (4)

		Positions.Add(FVector(0, -47.55, 15.45)); //6th vert

		TrianglesIndices.Add(0);
		TrianglesIndices.Add(1);
		TrianglesIndices.Add(2);

		TrianglesIndices.Add(0);
		TrianglesIndices.Add(2);
		TrianglesIndices.Add(3);

		TrianglesIndices.Add(0);
		TrianglesIndices.Add(3);
		TrianglesIndices.Add(4);

		TrianglesIndices.Add(0);
		TrianglesIndices.Add(4);
		TrianglesIndices.Add(5);

		TrianglesIndices.Add(0);
		TrianglesIndices.Add(5);
		TrianglesIndices.Add(1);
	}

#pragma endregion

	//Cube
#pragma region
	
	if (cube == true)
	{
		//Face Front
		Positions.Add(FVector(0, 0, 0)); //1st vert
		Positions.Add(FVector(0, 50, 0)); //2nd vert
		Positions.Add(FVector(0, 50, 50)); //3rd vert
		Positions.Add(FVector(0, 0, 50)); //4th vert

		//Face Back
		Positions.Add(FVector(50, 0, 0)); //5th vert
		Positions.Add(FVector(50, 50, 0)); //6th vert
		Positions.Add(FVector(50, 50, 50)); //7th vert
		Positions.Add(FVector(50, 0, 50)); //8th vert

		//Face Front
		TrianglesIndices.Add(0);
		TrianglesIndices.Add(1);
		TrianglesIndices.Add(2);
		TrianglesIndices.Add(2);
		TrianglesIndices.Add(3);
		TrianglesIndices.Add(0);

		//Face Back
		TrianglesIndices.Add(5);
		TrianglesIndices.Add(4);
		TrianglesIndices.Add(7);
		TrianglesIndices.Add(7);
		TrianglesIndices.Add(6);
		TrianglesIndices.Add(5);

		//Face Left
		TrianglesIndices.Add(4);
		TrianglesIndices.Add(0);
		TrianglesIndices.Add(3);
		TrianglesIndices.Add(3);
		TrianglesIndices.Add(7);
		TrianglesIndices.Add(4);

		//Face Right
		TrianglesIndices.Add(1);
		TrianglesIndices.Add(5);
		TrianglesIndices.Add(6);
		TrianglesIndices.Add(6);
		TrianglesIndices.Add(2);
		TrianglesIndices.Add(1);

		//Face Top
		TrianglesIndices.Add(3);
		TrianglesIndices.Add(2);
		TrianglesIndices.Add(6);
		TrianglesIndices.Add(6);
		TrianglesIndices.Add(7);
		TrianglesIndices.Add(3);

		//Face Bottom
		TrianglesIndices.Add(4);
		TrianglesIndices.Add(5);
		TrianglesIndices.Add(1);
		TrianglesIndices.Add(1);
		TrianglesIndices.Add(0);
		TrianglesIndices.Add(4);
	}

#pragma endregion

	// - UV (Origin is TOP-LEFT of texture)
	UVs.Add({ 0,1 }); // 1st vert
	UVs.Add({ 1,1 }); // 2nd vert
	UVs.Add({ 1,0 }); // 3rd vert
	UVs.Add({ 0,0 }); // 4th vert
	if (cube == true || pentagon == true && square == false)
	{
		UVs.Add({ 0,0 }); // 4th vert
		UVs.Add({ 1,0 }); // 3rd vert

		if (cube == true)
		{
			UVs.Add({ 1,1 }); // 2nd vert
			UVs.Add({ 0,1 }); // 1st vert
		}
	}


	ProceduralMesh->CreateMeshSection(0, Positions, TrianglesIndices, TArray<FVector>(), UVs, TArray<FColor>(), TArray<FProcMeshTangent>(), true);
}

// Called every frame
void AProceduralCubeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Debug spheres
	for (auto& Pos : Positions)
	{
		FVector NewPosition = GetActorTransform().TransformPosition(Pos);
		DrawDebugSphere(GetWorld(), NewPosition, 25.f, 8, FColor::Cyan);
	}

	//Points
	DrawDebugPoint(GetWorld(), Positions[0] + RootComponent->GetRelativeLocation(), 10.0f, FColor::Black); //0
	DrawDebugPoint(GetWorld(), Positions[1] + RootComponent->GetRelativeLocation(), 10.0f, FColor::Cyan); //1
	DrawDebugPoint(GetWorld(), Positions[2] + RootComponent->GetRelativeLocation(), 10.0f, FColor::White); //2
	DrawDebugPoint(GetWorld(), Positions[3] + RootComponent->GetRelativeLocation(), 10.0f, FColor::Red); //3
	if (cube == true || pentagon == true && square == false)
	{
		DrawDebugPoint(GetWorld(), Positions[4] + RootComponent->GetRelativeLocation(), 10.0f, FColor::Green); //4
		DrawDebugPoint(GetWorld(), Positions[5] + RootComponent->GetRelativeLocation(), 10.0f, FColor::Yellow); //5
		if (cube == true)
		{
			DrawDebugPoint(GetWorld(), Positions[6] + RootComponent->GetRelativeLocation(), 10.0f, FColor::Blue); //6
			DrawDebugPoint(GetWorld(), Positions[7] + RootComponent->GetRelativeLocation(), 10.0f, FColor::Purple); //7
		}
	}
}