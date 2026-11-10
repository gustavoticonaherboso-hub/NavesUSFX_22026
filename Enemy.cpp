// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"



AEnemy::AEnemy()
{
    PrimaryActorTick.bCanEverTick = true;


 
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(
        TEXT("MeshPrueba")
        );

    SetRootComponent(Mesh);



    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
        TEXT("StaticMesh'/Game/StarterContent/Architecture/Pillar_50x500.Pillar_50x500'")
    );

    if (MeshAsset.Succeeded())
    {
        Mesh->SetStaticMesh(MeshAsset.Object);
    }
}

// BEGIN PLAY

void AEnemy::BeginPlay()
{
    Super::BeginPlay();


    // CENTRO

    posicionCentro = GetActorLocation();


    // DERECHA

    posicionDerecha =
        posicionCentro + FVector(0.0f, 650.0f, 0.0f);


    // IZQUIERDA

    posicionIzquierda =
        posicionCentro + FVector(0.0f, -1250.0f, 0.0f);

// NORTE

    posicionNorte =
        posicionCentro + FVector(0.0f, 0.0f, 300.0f);


    // SUR

    posicionSur =
        posicionCentro + FVector(0.0f, 0.0f, -300.0f);


    // VELOCIDADES

    incremento = 9.0f;

    incrementoU = 5.0f;

    incrementoZ = 0.0f;


    // INICIALIZAR MOVIMIENTO Y

    posicionInicialY = posicionDerecha;

    posicionActualY = posicionDerecha;

    posicionFinalY = posicionIzquierda;


    // INICIALIZAR MOVIMIENTO Z

    posicionInicialZ = posicionCentro;

    posicionActualZ = posicionCentro;

    posicionFinalZ = posicionCentro;

    moverseZ = true;


    // COMENZAR EN LA DERECHA

    etapa = 0;

    SetActorLocation(posicionDerecha);
}


void AEnemy::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    moverTrayectoria();
}


// MOVIMIENTO EN Y

void AEnemy::moverY()
{
    if (GetMoverseY())
    {
        n++;

        if (moverse)
        {
            if (posicionActualY.Y > posicionFinalY.Y)
            {
                posicionActualY.Y -= incremento;
            }
            else
            {
                moverse = false;
            }
        }
        else
        {
            if (posicionActualY.Y < posicionInicialY.Y)
            {
                posicionActualY.Y += incremento;
            }
            else
            {
                moverse = true;
            }
        }

        SetActorLocation(posicionActualY);
    }
}


// MOVIMIENTO EN Z

void AEnemy::moverZ()
{
    // Se mantiene la función,
    // pero no realiza movimiento vertical.

    if (incrementoZ == 0.0f)
    {
        return;
    }
}


// TRAYECTORIA COMPLETA


void AEnemy::moverTrayectoria()
{
    FVector posicionActual = GetActorLocation();


    // DERECHA -> CENTRO

    if (etapa == 0)
    {
        if (posicionActual.Y > posicionCentro.Y)
        {
            posicionActual.Y -= incremento;
        }
        else
        {
            posicionActual.Y = posicionCentro.Y;

            etapa = 1;
        }
    }


    // CENTRO -> NORTE

    else if (etapa == 1)
    {
        if (posicionActual.Z < posicionNorte.Z)
        {
            posicionActual.Z += incrementoU;
        }
        else
        {
            posicionActual.Z = posicionNorte.Z;

            etapa = 2;
        }
    }

    // NORTE -> CENTRO


    else if (etapa == 2)
    {
        if (posicionActual.Z > posicionCentro.Z)
        {
            posicionActual.Z -= incrementoU;
        }
        else
        {
            posicionActual.Z = posicionCentro.Z;

            etapa = 3;
        }
    }

    // CENTRO -> SUR


    else if (etapa == 3)
    {
        if (posicionActual.Z > posicionSur.Z)
        {
            posicionActual.Z -= incrementoU;
        }
        else
        {
            posicionActual.Z = posicionSur.Z;

            etapa = 4;
        }
    }


    // SUR -> CENTRO

    else if (etapa == 4)
    {
        if (posicionActual.Z < posicionCentro.Z)
        {
            posicionActual.Z += incrementoU;
        }
        else
        {
            posicionActual.Z = posicionCentro.Z;

            etapa = 5;
        }
    }

    // CENTRO -> IZQUIERDA


    else if (etapa == 5)
    {
        if (posicionActual.Y > posicionIzquierda.Y)
        {
            posicionActual.Y -= incremento;
        }
        else
        {
            posicionActual.Y = posicionIzquierda.Y;

            etapa = 6;
        }
    }


    // IZQUIERDA -> CENTRO

    else if (etapa == 6)
    {
        if (posicionActual.Y < posicionCentro.Y)
        {
            posicionActual.Y += incremento;
        }
        else
        {
            posicionActual.Y = posicionCentro.Y;

            etapa = 7;
        }
    }


    // CENTRO -> NORTE

    else if (etapa == 7)
    {
        if (posicionActual.Z < posicionNorte.Z)
        {
            posicionActual.Z += incrementoU;
        }
        else
        {
            posicionActual.Z = posicionNorte.Z;

            etapa = 8;
        }
    }

    // NORTE -> CENTRO


    else if (etapa == 8)
    {
        if (posicionActual.Z > posicionCentro.Z)
        {
            posicionActual.Z -= incrementoU;
        }
        else
        {
            posicionActual.Z = posicionCentro.Z;

            etapa = 9;
        }
    }


    // CENTRO -> SUR


    else if (etapa == 9)
    {
        if (posicionActual.Z > posicionSur.Z)
        {
            posicionActual.Z -= incrementoU;
        }
        else
        {
            posicionActual.Z = posicionSur.Z;

            etapa = 10;
        }
    }


    // SUR -> CENTRO

    else if (etapa == 10)
    {
        if (posicionActual.Z < posicionCentro.Z)
        {
            posicionActual.Z += incrementoU;
        }
        else
        {
            posicionActual.Z = posicionCentro.Z;

            etapa = 11;
        }
    }

    // CENTRO -> DERECHA
    else if (etapa == 11)
    {
        if (posicionActual.Y < posicionDerecha.Y)
        {
            posicionActual.Y += incremento;
        }
        else
        {
            posicionActual.Y = posicionDerecha.Y;

            // Volver a empezar
            etapa = 0;
        }
    }

    // APLICAR POSICIÓN

    SetActorLocation(posicionActual);
}