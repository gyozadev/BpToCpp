// Fill out your copyright notice in the Description page of Project Settings.


#include "ConeActor.h"

// Sets default values
AConeActor::AConeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	ConeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	Scene->SetupAttachment(GetRootComponent());
	ConeMesh->SetupAttachment(Scene);

	bIsUp = true;
	Speed = 50;
	Max = 200;

}

// Called when the game starts or when spawned
void AConeActor::BeginPlay()
{
	Super::BeginPlay();

	//setting default values based on location of object
	const FVector Location = GetActorLocation();
	CurrentZ = Location.Z;
	MinHeight = Location.Z;
	MaxHeight = Location.Z + Max;
	bIsUp = true;
	
}

void AConeActor::TestFunc(int32 Val)
{
	UE_LOG(LogTemp, Warning, TEXT("Test Func Called with value %d"), Val);
}

// Called every frame
void AConeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float Val = DeltaTime * Speed;

	//Is the object moving up or down?
	if (bIsUp)
	{
		CurrentZ = CurrentZ + Val;
	}
	else
	{
		CurrentZ = CurrentZ - Val;
	}

	FVector Location = GetActorLocation();
	Location.Z = CurrentZ;

	SetActorLocation(Location);

	if (CurrentZ > MaxHeight)
	{
		bIsUp = false;
	}
	else if (CurrentZ < MinHeight) {
		bIsUp = true;
	}
}

