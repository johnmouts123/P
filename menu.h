//
// Created by João Mota on 16/04/2023.
//

#ifndef PROGRAMA_O_MENU_H
#define PROGRAMA_O_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

int criarmenu () {


    int escolha = 0;

    do {
        system("cls"); // limpar o ecrã
        printf("---------- Bem vindo ao Metro Mondego ---------- \n"
               "---------- 0 - Sair ---------------------------- \n"
               "---------- 1 - Paragens ------------------------ \n"
               "---------- 2 - Linhas -------------------------- \n"
               "---------- 3 - Calculo de percursos ------------ \n"
               "---------- 4 - Ajuda --------------------------- \n"
               "->");
        scanf("%d",&escolha);

    } while ( escolha > 4 || escolha < 0);
};

int paragens () {

    int escolha_paragens;

    do {
        system("cls");
        printf("---------- 1 - Registar Paragem ------------\n"
               "---------- 2 - Eliminar Paragem ------------\n"
               "---------- 3 - Visualizar Paragens ----------\n"
               "->");
        scanf("%d",&escolha_paragens);
    } while (escolha_paragens > 3 || escolha_paragens < 1);
};


#endif
