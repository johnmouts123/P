//
// Created by João Mota on 16/04/2023.
//

#ifndef PROGRAMA_O_MAIN_H
#define PROGRAMA_O_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 100

typedef struct Paragem_Info {
    char nome[20];
    char codigo[5];
} Paragem_Info;



int gerar_codigo( char* codigo) {

    char digitos[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i=0 ; i<4 ; i++)
        codigo[i] = digitos[rand() % 36]; // 36 Número / Algarismos

    return 0;
};

int mostra_paragens () {

    Paragem_Info paragens_existentes[N];
    char codigo;
    int num_paragens=0, num_codigos=0;


    strcpy(paragens_existentes[0].nome, "Teste");
    gerar_codigo(paragens_existentes[0].codigo);
    num_paragens++;

    strcpy(paragens_existentes[1].nome, "Teste 2");
    gerar_codigo(paragens_existentes[1].codigo);
    num_paragens++;

    strcpy(paragens_existentes[2].nome, "Teste 3");
    gerar_codigo(paragens_existentes[2].codigo);
    num_paragens++;

    strcpy(paragens_existentes[3].nome, "Teste 3");
    gerar_codigo(paragens_existentes[3].codigo);
    num_paragens++;


    printf("Paragens existentes: \n\n");

    for (int i=0 ; i<num_paragens ; i++){
        printf("Nome -> %s\n"
               "Codigo -> %s\n\n", paragens_existentes[i].nome,paragens_existentes[i].codigo);
    }
};


#endif
