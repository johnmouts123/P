//
// Created by João Mota on 01/05/2023.
//

#include "utils.h"

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Função para limpar buffer do teclado
}

void gerar_codigo(char * codigo) {

    const char * c = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int tam = strlen(c);

    for (int i = 0; i < 4; i++) {
        codigo[i] = c[rand() % tam];
    }

    codigo[4] = '\0';
}

void limparEcra() {
    system("cls");
}


