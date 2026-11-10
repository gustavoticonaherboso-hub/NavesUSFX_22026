// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "fabrica_enemigos_acuaticos.generated.h"

UCLASS()
class USFX4_API Afabrica_enemigos_acuaticos : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Afabrica_enemigos_acuaticos();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
