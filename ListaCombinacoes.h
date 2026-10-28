#ifndef LISTACOMBINACOES_H
#define LISTACOMBINACOES_H

#include <stdio.h>
#include <stdlib.h>

#include "PokeLista.h"

typedef struct{
    Pokelista** Combinacoes;
}ListaCombinacoes;

void inicializaCombinacoes(ListaCombinacoes* lista, int nCombinacoes);

int achaCombinacoes(ListaCombinacoes* lista, Pokelista* listaAux, Pokelista* listaPokemon, int* idxComb, int idxPokemon, int pokeMax);


#endif