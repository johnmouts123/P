//
// Created by João Mota on 16/04/2023.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"
#include "menu.h"

int main () {

    int escolha , escolha_paragens;

    escolha = criarmenu();

    switch (escolha) {

        // ---------- 0 - Sair ----------
        case 0:
            printf("Obrigado pela preferencia");
            return 0;
            break;


            // ---------- 1 - Paragens ----------
        case 1:
            escolha_paragens=paragens();
            switch (escolha_paragens) {
                case 1:

                    return 0;
                    break;


                case 2:

                    return 0;
                    break;


                case 3:
                    mostra_paragens();
                    return 0;
                    break;
            }




    }

};
