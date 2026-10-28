#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Treinador.h"

void InicializarTreinador(Treinador* user, char nome[12], int id){
    strcpy(user->nome,nome);
    user->lista = inicializaLista();
    user->ID = id;
};

void ImprimirTreinador(Treinador* user){
    printf("===================\n");
    printf("Identificador: %d\n", user->ID);
    printf("Nome: %s\n", user->ID);
    printf("===================\n");
};

void RetirarPokemon(Treinador* user){
    removeTodos(user->lista);
}

char* getNomeTreinador(Treinador* user){return user->nome;}
int getIDTreinador(Treinador* user){return user->ID;}
Pokelista* getListaTren(Treinador* user){return user->lista;}

char* setNomeTreinador(Treinador* user, char* nome){return user->nome;}
int setIDTreinador(Treinador* user, int ID){return user->ID;}
