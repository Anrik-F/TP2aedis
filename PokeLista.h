#ifndef POKELISTA_H
#define POKELISTA_H

#include <stdio.h>

#include "Pokemon.h"

typedef struct Celula {
    Pokemon* pokemon;
    struct Celula* proximo;
}Celula;

//Essa struct pode ser considerada A LISTA propriamente dita
typedef struct{
    Celula* primeiro;
    Celula* ultimo;
    int tamanho;
}Pokelista;


Pokelista* inicializaLista();

void insercao(Pokelista* lista, Pokemon* pokemon);

void remocao(Pokelista* cabecalho, Pokemon* pokemon);

void removeTodos(Pokelista* cabecalho);

int removeUltimo(Pokelista* lista);

void copiarLista(Pokelista* destino, Pokelista* original);

int imprimeTodosPokemon(Pokelista* lista);

Pokemon* buscaPokemonLista(Pokelista* lista, int pokeID);

int somarPoder(Pokelista* lista);

int somarEnergia(Pokelista* lista);

#endif