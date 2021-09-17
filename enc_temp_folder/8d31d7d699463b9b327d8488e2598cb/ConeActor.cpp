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

	Speed = 50;
	Max = 200;

}

// Called when the game starts or when spawned
void AConeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

