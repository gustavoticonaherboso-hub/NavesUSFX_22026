// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class USFX4_API AEnemy : public AActor
{
    GENERATED_BODY()

public:

    AEnemy();

protected:

    virtual void BeginPlay() override;

public:

    virtual void Tick(float DeltaTime) override;


    // MESH DEL ENEMIGO

    UPROPERTY()
        class UStaticMeshComponent* Mesh;

    // MOVIMIENTO EN Y

    FVector posicionInicialY;
    FVector posicionActualY;
    FVector posicionFinalY;

    bool y = true;

    int n = 0;

    float incremento = 9.0f;

    bool moverse = true;

    FORCEINLINE bool GetMoverseY()
    {
        return y;
    }

    FORCEINLINE void SetMoverseY(bool m = false)
    {
        y = m;
    }

    void moverY();


    // MOVIMIENTO EN Z

    FVector posicionInicialZ;
    FVector posicionActualZ;
    FVector posicionFinalZ;

    float incrementoZ = 5.0f;

    bool moverseZ = true;

    void moverZ();



    int etapa = 0;

    FVector posicionCentro;
    FVector posicionDerecha;
    FVector posicionIzquierda;
    FVector posicionNorte;
    FVector posicionSur;

    float incrementoU = 5.0f;

    void moverTrayectoria();
};