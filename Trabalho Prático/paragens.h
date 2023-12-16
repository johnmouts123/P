//
// Created by João Mota on 17/04/2023.
//

#ifndef TRABALHO_PRÁTICO_PARAGENS_H
#define TRABALHO_PRÁTICO_PARAGENS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Paragem {
    char nome[50];
    char codigo[5];
    int num_linhas;
    char ** linhas;
}Paragem;

void codigo_paragem(char * codigo, char * paragem_info);
int paragem_existe(const char *nome);
void registar_paragens();
void eliminar_paragens();
void visualizar_paragens();
void paragens_default();


#endif //TRABALHO_PRÁTICO_PARAGENS_H
