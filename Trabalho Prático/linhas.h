//
// Created by João Mota on 17/04/2023.
//

#ifndef LINHAS_H
#define LINHAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "paragens.h"
#include "utils.h"

typedef struct Linha
{
    char nome[50];
    Paragem * paragens;
    char **codigo_paragens;
    int num_paragens;
}Linha;

extern Linha * linhas;
extern int num_linhas;

void adicionar_linha(char *nome);
void adicionar_paragem(Linha *linha, char *paragem_info, char **pString);
void linhas_default();
void apagar_linha();
void atualizar_linha();
void ver_linhas();
Linha* encontra_linha(char *nome);
void liga_paragem_linha(char *n_linha_2, char *paragem_info);
void desliga_paragem_linha(char *n_linha_2, char *paragem_info);








#endif //LINHAS_HS