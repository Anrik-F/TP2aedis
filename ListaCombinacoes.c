#include <stdio.h>
#include <stdlib.h>

#include "PokeLista.h"
#include "ListaCombinacoes.h"

void inicializaCombinacoes(ListaCombinacoes* lista, int nCombinacoes){
    Pokelista** listaDeCombinacoes = (Pokelista**) malloc(sizeof(Pokelista*)*nCombinacoes);

    lista->Combinacoes = listaDeCombinacoes;

    for (int i = 0; i < nCombinacoes; i++){
        lista->Combinacoes[i] = inicializaLista();
    }
}

int achaCombinacoes(ListaCombinacoes* lista, Pokelista* listaAux, Pokelista* listaPokemon, int* idxComb, int idxPokemon, int pokeMax){
    //Adiciona listaAux à lista de combinacoes
    copiarLista(lista->Combinacoes[*idxComb], listaAux);
    *idxComb += 1; 

    for (int i = idxPokemon; i < pokeMax; i++){
        //Insere o Pokemon em listaPokemon[idxPokemon] na listaAux
        Celula* celAux = listaPokemon->primeiro;
        for (int j = 0; j < i; j++){
            celAux = celAux->proximo;
        }

        insercao(listaAux, celAux->pokemon);
        
        //Move para a proxima interacao
        achaCombinacoes(lista, listaAux, listaPokemon, idxComb, i + 1, pokeMax);

        //Remove o pokemon fixado
        removeUltimo(listaAux);
    }
    return 1;
}