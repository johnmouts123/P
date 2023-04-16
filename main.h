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
    int num_paragens;
} Paragem_Info;


    Paragem_Info paragens_existentes[N];
    int num_paragens = 0;



int gerar_codigo( char* codigo) {

    char digitos[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i=0 ; i<4 ; i++)
        codigo[i] = digitos[rand() % 36]; // 36 Números / Algarismos

    return 0;
};



int registar_paragem () {

    char codigo;

    printf("Paragem que deseja adicionar:");
    scanf("%s", &paragens_existentes[num_paragens].nome);
    strcpy(paragens_existentes[num_paragens].codigo, gerar_codigo(codigo));
    num_paragens++;

    printf("Paragem adicionada com êxito");
}


int eliminar_paragem () {

    char codigo[5];

    printf("Codigo da paragem:");
    scanf("%s",&codigo);
    int i;
    for (i = 0; i < num_paragens; i++) {
        if (strcmp(paragens_existentes[i].codigo, codigo) == 0) {
            int j;
            for (j = i; j < num_paragens - 1; j++) {
                paragens_existentes[j] = paragens_existentes[j+1];
            }
            num_paragens--;
            printf("Paragem eliminada com sucesso!\n");
        }
    }
    printf("Nao foi encontrada nenhuma paragem com o codigo %s.\n", codigo);

}


int mostra_paragens () {


    strcpy(paragens_existentes[num_paragens].nome, "Paragem 1");
    gerar_codigo(paragens_existentes[num_paragens].codigo);
    num_paragens++;

    strcpy(paragens_existentes[num_paragens].nome, "Paragem 2");
    gerar_codigo(paragens_existentes[num_paragens].codigo);
    num_paragens++;

    strcpy(paragens_existentes[num_paragens].nome, "Paragem 3");
    gerar_codigo(paragens_existentes[num_paragens].codigo);
    num_paragens++;



    printf("Paragens existentes: \n\n");

    for (int i = 0; i < num_paragens; i++) {
        if (strlen(paragens_existentes[i].nome) > 0) { // Mostra apenas as paragens que têm conteúdo preenchido
            printf("Nome -> %s\n"
                   "Codigo -> %s\n\n", paragens_existentes[i].nome,paragens_existentes[i].codigo);
        }
    }
}




#endif
