#ifndef TREINADOR_H
#define TREINADOR_H

#include <stdio.h>

#include "PokeLista.h"
#include "Pokemon.h"

typedef struct{
    int ID;
    char nome[12];
    Pokelista* lista;
}Treinador;

void InicializarTreinador(Treinador* user, char nome[12], int id);

void RetirarPokemon(Treinador* user);

void ImprimirTreinador(Treinador* user);

char* getNomeTreinador(Treinador* user);
int getIDTreinador(Treinador* user);
Pokelista* getListaTren(Treinador* user);

char* setNomeTreinador(Treinador* user, char* nome);
int setIDTreinador(Treinador* user, int ID);

#endif