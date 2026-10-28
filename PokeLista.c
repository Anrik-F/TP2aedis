#include <stdio.h>
#include <stdlib.h>

#include "PokeLista.h"

Pokelista* inicializaLista(){
    Pokelista* cabecalho;
    cabecalho = (Pokelista*) malloc(sizeof(Pokelista));

    cabecalho->primeiro = NULL;
    cabecalho->ultimo = NULL;
    cabecalho->tamanho = 0;

    return cabecalho;
}

void insercao(Pokelista* lista, Pokemon* pokemon){
    //Insere a primeira celula
    if (lista->primeiro == NULL){
        Celula* cell;
        cell = (Celula*) malloc(sizeof(Celula));

        cell->pokemon = pokemon;
        cell->proximo = NULL;

        lista->primeiro = cell;
        lista->ultimo = cell;
        lista->tamanho = 1;
    }
    //Insere na ultima posicao
    else if (lista->primeiro != NULL) {
        Celula* cell;
        cell = (Celula*) malloc(sizeof(Celula));

        cell->pokemon = pokemon;
        cell->proximo = NULL;

        lista->ultimo->proximo = cell;
        lista->ultimo = cell;
        lista->tamanho++;
    }
}

void remocao(Pokelista* cabecalho, Pokemon* pokemonDado){
    Celula* cell = cabecalho->primeiro;
    Celula* cellAnterior;
    int cellPosicao = 1;
    
    //Acha o pokemonDado na lista
    while (pokemonDado->ID != cell->pokemon->ID){
        cellAnterior = cell;
        cell = cell->proximo;
        cellPosicao++;
    }

    //Remove 1 posição
    if (cellPosicao == 1){
        cabecalho->primeiro = cabecalho->primeiro->proximo;
        cabecalho->tamanho--;
        free(cell);
    }
    //Remove posição N
    else if (cellPosicao > 1 && cellPosicao < cabecalho->tamanho){
        cellAnterior->proximo = cell->proximo;
        cabecalho->tamanho--;
        free(cell);
    }
    //Remove última posição
    else if (cellPosicao == cabecalho->tamanho){
        cellAnterior->proximo = NULL;
        cabecalho->tamanho--;
        free(cell);
    }
}

int removeUltimo(Pokelista* lista){
    if (lista->primeiro == NULL){
        return 0;
    }
    
    if (lista->primeiro == lista->ultimo){
        free(lista->primeiro);
        lista->primeiro = NULL;
        lista->ultimo = NULL;
        lista->tamanho = 0;
        return 1;
    }

    Celula* cell = lista->primeiro;
    while (cell->proximo != lista->ultimo){
        cell = cell->proximo;
    }

    free(lista->ultimo);
    cell->proximo = NULL;
    lista->ultimo = cell;
    lista->tamanho--;

    return 1;
}

void removeTodos(Pokelista* cabecalho){
    Celula* atual = cabecalho->primeiro;
    Celula* prox;

    while (atual != NULL){
        prox = atual->proximo;

        free(atual);

        atual = prox;
    }
    
    cabecalho->primeiro = NULL;
    cabecalho->ultimo = NULL;
}

void copiarLista(Pokelista* destino, Pokelista* original){
    Celula* celAux = original->primeiro;
    
    while (celAux != NULL){
        insercao(destino, celAux->pokemon);
        
        celAux = celAux->proximo;
    }
}

int imprimeTodosPokemon(Pokelista* lista){
    //Verifica se não é uma lista vazia
    if(lista->primeiro == NULL){
        printf("Lista vazia");
        return 0;
    }

    Celula* cellAtual = lista->primeiro;

    while (cellAtual != NULL) {
        imprimePokemon(cellAtual->pokemon);
        cellAtual = cellAtual->proximo;
    }

    return 1;
}

Pokemon* buscaPokemonLista(Pokelista* cabecalho, int pokeID){
    Celula* cell = cabecalho->primeiro;
    
    while (pokeID != cell->pokemon->ID){
        cell = cell->proximo;
    }

    Pokemon* buscado = cell->pokemon;

    return buscado;
}

int somarPoder(Pokelista* lista){
    Celula* cell = lista->primeiro;
    int soma = 0;
    
    while(cell != NULL){
        soma += cell->pokemon->poder;
        cell = cell->proximo;
    }

    return soma;
};

int somarEnergia(Pokelista* lista){
    Celula* cell = lista->primeiro;
    int soma = 0;
    
    while(cell != NULL){
        soma += cell->pokemon->energia;
        cell = cell->proximo;
    }

    return soma;
};