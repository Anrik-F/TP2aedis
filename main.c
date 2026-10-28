#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#include "PokeLista.h"
#include "Pokemon.h"
#include "Treinador.h"
#include "ListaCombinacoes.h"

int nTreinadores = 2;

int main() {
    //Abre e verifica se o arquivo foi aberto
    FILE *arqEntrada = fopen("ArquivoDeEntrada.txt", "r");

    if(arqEntrada == NULL) {
        printf("O Árquivo não abriu");
        return 1;
    }
    
    //Inicializa Treinadores
    Treinador treinadores[nTreinadores];

    for (int idTren = 0; idTren < nTreinadores; idTren++){
        char nome[30];
        
        fscanf(arqEntrada, "%s", nome);
        
        InicializarTreinador(&treinadores[idTren+1], nome, idTren);
    }
    
    //Inicializa Pokemons Disponiveis
    Pokelista* listaDisponiveis = inicializaLista();
    int nPokeDisponiveis;
    int energiaDisponivel;
    fscanf(arqEntrada, "%d ", &nPokeDisponiveis);
    fscanf(arqEntrada, "%d ", &energiaDisponivel);

    for (int i = 0; i < nPokeDisponiveis; i++){
        int id;
        char nome[30];
        char tipo[30];
        int poder;
        int energia;
        
        fscanf(arqEntrada, "%d %s %s %d %d", &id, nome, tipo, &poder, &energia);

        Pokemon* pokemon = inicializaPokemon(id, nome, tipo, poder, energia);
        
        insercao(listaDisponiveis, pokemon);
    }

    fclose(arqEntrada);

    //Calcula o numero de combinacoes possiveis
    int nCombinacoes = pow(2, nPokeDisponiveis);
    
    //Loop de combinacoes
    ListaCombinacoes listaCombinacoes;
    inicializaCombinacoes(&listaCombinacoes, nCombinacoes);
    
    Pokelista* listaAux = inicializaLista();

    int idxComb = 0;
    
    removeTodos(listaAux);
    achaCombinacoes(&listaCombinacoes, listaAux, listaDisponiveis, &idxComb, 0, nPokeDisponiveis);
    
    for (int j = 0; j < nCombinacoes; j++){
        printf("COMBINACAO %d\n", j+1);
        imprimeTodosPokemon(listaCombinacoes.Combinacoes[j]);
        printf("----------------------------\n\n");
    }
    

    return 0;
}