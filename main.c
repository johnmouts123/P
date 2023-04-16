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


    while (1) {
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

                    // ---------- 1 - Registar paragem ----------
                    case 1:
                        registar_paragem();
                        return 0;
                        break;

                        // ---------- 2 - Eliminar paragem ----------
                    case 2:
                        eliminar_paragem();
                        return 0;
                        break;

                        // ---------- 3 - Visualizar paragens ----------
                    case 3:
                        mostra_paragens();
                        return 0;
                        break;
                }

                break;

        }
    }
};
