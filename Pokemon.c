#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pokemon.h"

Pokemon* inicializaPokemon(int ID, char nome[30], char tipo[30], int poder, int energia){
    Pokemon* poke = (Pokemon*) malloc(sizeof(Pokemon));

    poke->ID = ID;
    strcpy(poke->nome, nome);
    strcpy(poke->tipo, tipo);
    poke->poder = poder;
    poke->energia = energia;

    return poke;
}

void imprimePokemon(Pokemon* pokemon){
    printf("===================\n");
    printf("ID: %d\n", pokemon->ID);
    printf("Nome: %s\n", pokemon->nome);
    printf("Tipo: %s\n", pokemon->tipo);
    printf("Poder: %d\n", pokemon->poder);
    printf("Energia: %d\n", pokemon->energia);
    printf("===================\n");
}

//GETeres
int getIDPokemon(Pokemon* pokemon){return pokemon->ID;};
char* getNomePokemon(Pokemon* pokemon){return pokemon->nome;}
char* getTipoPokemon(Pokemon* pokemon){return pokemon->tipo;}
int getPoderPokemon(Pokemon* pokemon){return pokemon->poder;}
int getEnergiaPokemon(Pokemon* pokemon){return pokemon->energia;}

//SETeres
int setIDPokemon(Pokemon* pokemon, int ID){pokemon->ID = ID;}
char* setNomePokemon(Pokemon* pokemon, char* nome){strcpy(pokemon->nome, nome);}
char* setTipoPokemon(Pokemon* pokemon, char* tipo){strcpy(pokemon->tipo, tipo);}
int setPoderPokemon(Pokemon* pokemon, int poder){pokemon->poder = poder;}
int setEnergiaPokemon(Pokemon* pokemon, int energia){pokemon->energia = energia;}

