// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "C_KingPawn.generated.h"

UCLASS()
class BATTLECOLOSSEUM_API AC_KingPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AC_KingPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// FVector ForwordDirection;


	UFUNCTION()
		void Turn(float Value);
	UFUNCTION()
		void Lookup(float Value);
	UFUNCTION()
		void MoveForward(float Value);
	UFUNCTION()
		void MoveRight(float Value);
	UFUNCTION()
		void ZoomIn(float Value);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UCameraComponent* Camera;
//	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		//class UArrowComponent* CastArrow;
	
};
