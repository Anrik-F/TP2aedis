#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>

typedef struct{
    int ID;
    char nome[30];
    char tipo[30];
    int poder;
    int energia;
}Pokemon;


Pokemon* inicializaPokemon(int ID, char nome[30], char tipo[30], int poder, int energia);

void imprimePokemon(Pokemon* pokemon);

//GETeres
int getIDPokemon(Pokemon* pokemon);
char* getNomePokemon(Pokemon* pokemon);
char* getTipoPokemon(Pokemon* pokemon);
int getPoderPokemon(Pokemon* pokemon);
int getEnergiaPokemon(Pokemon* pokemon);

//SETeres
int setIDPokemon(Pokemon* pokemon, int ID);
char* setNomePokemon(Pokemon* pokemon, char* nome);
char* setTipoPokemon(Pokemon* pokemon, char* tipo);
int setPoderPokemon(Pokemon* pokemon, int poder);
int setEnergiaPokemon(Pokemon* pokemon, int energia);

#endif