// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConeActor.generated.h"

UCLASS()
class BPTOCPP_API AConeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConeActor();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* ConeMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ConeActor")
		uint8 bIsUp:1;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ConeActor")
		float MinHeight;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ConeActor")
		float MaxHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConeActor")
		float Max;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ConeActor")
		float CurrentZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConeActor")
		float Speed;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




public:	

	UFUNCTION(BlueprintCallable, Category = "Cone Functions")
		void TestInputOutput(const int32 InVal, AConeActor*& ConeActor, int32& OutVal1, int32& OutVal2);


	UFUNCTION(BlueprintCallable, Category = "Cone Functions")
		void TestFunc(const int32 Val);

	UFUNCTION(BlueprintPure, Category = "Cone Functions", meta = (HideSelfPin = "true"))
		int32 TestPureFunc();

	UFUNCTION(BlueprintImplementableEvent, Category = "Cone Functions")
		void TestImplementableFunc(int32 Val);

	UFUNCTION(BlueprintNativeEvent, Category = "Cone Functions")
	void Explode();
	void Explode_Implementation();


	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
