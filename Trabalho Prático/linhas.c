#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linhas.h"
#include "paragens.h"

Linha * linhas = NULL;
int num_linhas = 0;

// Função para encontrar uma Linha pelo nome.
Linha * encontra_linha(char * nome) {

    for (int i = 0; i < num_linhas; i++) {
        // Se o nome da linha atual corresponder ao nome procurado, retorna a linha
        if (strcmp(linhas[i].nome, nome) == 0) {
            return & linhas[i];
        }
    }

    // Se nenhuma linha for encontrada, retorna NULL
    return NULL;
}



void linhas_default() {

    char *linhas_default[] = {
            "Vermelha",
            "Laranja",
            "Verde",
            "Azul-Marinho",
    };

    // Número de linhas predefinidas
    int num_linhas_default = sizeof(linhas_default) / sizeof(linhas_default[0]);

    // Array bidimensional de paragens predefinidas
    char *paragens_default[][5] = {
            {
                    "Cantanhede",
                    "Figueira da Foz",
                    "Bifurcacao de Lares",
                    "Lourical"
            },
            {
                    "Alfarelos",
                    "Soure",
                    "Pombal",
                    "Coimbra-B"
            },
            {
                    "Coimbra",
                    "Portagem",
                    "Polo III",
                    "Condeixa-a-Nova"
            },
            {
                    "Santa Apolonia",
                    "Hospital Pediatrico",
                    "Loja do Cidadao",
                    "Quinta da Fonte"
            }
    };

    // Para cada linha predefinida...
    for (int i = 0; i < num_linhas_default; i++) {
        // Adiciona a linha
        adicionar_linha(linhas_default[i]);
    }

    // Para cada linha predefinida...
    for (int i = 0; i < num_linhas_default; i++) {
        // Para cada paragem nessa linha...
        for (int j = 0; j < 4; j++) {
            // Encontra a linha correspondente pelo nome
            Linha * linha = encontra_linha(linhas_default[i]);

            // Adiciona a paragem à linha
            adicionar_paragem(linha, paragens_default[i][j], linha -> codigo_paragens);
        }
    }
}



void adicionar_linha(char * nome) {

    // Verifiqua se o nome já existe
    for (int i = 0; i < num_linhas; i++) {
        if (strcmp(linhas[i].nome, nome) == 0) {
            // Se o nome já existir, imprime uma mensagem de erro
            printf("Erro: Linha ja existente.\n");
            return;
        }
    }

    // Cria uma nova Linha
    Linha novaLinha;
    strcpy(novaLinha.nome, nome);
    novaLinha.paragens = NULL;
    novaLinha.codigo_paragens = NULL;
    novaLinha.num_paragens = 0;

    // Incrementa o número de linhas
    num_linhas++;
    // Realoca o array de linhas para acomodar a nova linha
    linhas = realloc(linhas, num_linhas * sizeof(Linha));
    // Adiciona a nova linha ao final do array
    linhas[num_linhas - 1] = novaLinha;

}



void liga_paragem_linha(char * n_linha_2, char * paragem_info) {

    // Encontrar a linha pelo respetivo nome
    Linha * linha = encontra_linha(n_linha_2);
    // Se a linha não for encontrada, imprime uma mensagem de erro
    if (linha == NULL) {
        printf("Erro: Linha nao encontrada.\n");
        return;
    }

    // Encontra a paragem pelo respetivo nome
    char codigoParagem[5];
    codigo_paragem(codigoParagem, paragem_info);

    // Se a paragem não for encontrada, imprime uma mensagem de erro
    if (strcmp(codigoParagem, "") == 0) {
        printf("Erro: Paragem nao encontrada.\n");
        return;
    }

    // Adiciona a paragem à linha
    adicionar_paragem(linha, paragem_info, codigoParagem);
}



void adicionar_paragem(Linha * linha, char * paragem_info, char ** codigo_paragens) {
    // Cria uma nova Paragem
    Paragem nova_paragem;
    strcpy(nova_paragem.nome, paragem_info);


    char codigo[5];
    gerar_codigo(codigo);

    // Incrementa o número de paragens da linha
    linha -> num_paragens++;

    // Realoca os arrays de paragens e códigos para acomodar a nova paragem
    linha -> paragens = realloc(linha -> paragens, linha -> num_paragens * sizeof(Paragem));
    linha -> codigo_paragens = realloc(linha -> codigo_paragens, linha -> num_paragens * sizeof(char * ));

    // Adiciona a nova paragem e seu código ao final dos arrays
    linha -> paragens[linha -> num_paragens - 1] = nova_paragem;
    linha -> codigo_paragens[linha -> num_paragens - 1] = malloc(5 * sizeof(char));
    strcpy(linha -> codigo_paragens[linha -> num_paragens - 1], codigo);
}



void desliga_paragem_linha(char * n_linha_2, char * paragem_info) {
    // Encontrar a linha pelo nome
    Linha * linha = encontra_linha(n_linha_2);
    // Se a linha não for encontrada, imprime uma mensagem de erro
    if (linha == NULL) {
        printf("Erro: Linha nao encontrada.\n");
        return;
    }

    // Verificar se a paragem está na linha
    bool encontrada = false;
    for (int i = 0; i < linha -> num_paragens; i++) {
        if (strcmp(linha -> paragens[i].nome, paragem_info) == 0) {
            encontrada = true;
            // Remover a paragem da linha
            for (int j = i; j < linha -> num_paragens - 1; j++) {
                linha -> paragens[j] = linha -> paragens[j + 1];
                linha -> codigo_paragens[j] = linha -> codigo_paragens[j + 1];
            }
            break;
        }
    }

    // Se a paragem não estiver na linha, imprime uma mensagem de erro
    if (!encontrada) {
        printf("Erro: Paragem nao pertencente a linha.\n");
        return;
    }

    // Decrementar o número de paragens da linha
    linha -> num_paragens--;

    printf("Paragem removida com sucesso.\n");
}



void atualizar_linha() {
    printf("\n                                                  Atualizar Linha \n");

    // Verificar se existem linhas registadas
    if (num_linhas == 0) {
        printf("Nao existem linhas registadas.\n");
        return;
    }


    char n_linha_2[50];
    printf("Linha que deseja atualizar: ");
    fgets(n_linha_2, sizeof(n_linha_2), stdin);
    n_linha_2[strcspn(n_linha_2, "\n")] = '\0'; // Remover a nova linha do fim do nome da linha

    // Encontra a linha pelo nome
    Linha * linha = encontra_linha(n_linha_2);

    // Verifica se a linha foi encontrada
    if (linha == NULL) {
        printf("Linha nao encontrada.\n");
        return;
    }

    // Solicitar o novo nome da linha
    char nome_atualizado[50];
    printf("Novo nome da linha: ");
    fgets(nome_atualizado, sizeof(nome_atualizado), stdin);
    nome_atualizado[strcspn(nome_atualizado, "\n")] = '\0';

    // Verifica se esse nome já existe
    for (int i = 0; i < num_linhas; i++) {
        if (strcmp(linhas[i].nome,nome_atualizado) == 0) {
            // Se o nome já existir, imprime uma mensagem de erro
            printf("Erro: Linha ja existe.\n");
            return;
        }
    }

    // Atualizar o nome da linha
    strcpy(linha -> nome,nome_atualizado);

    printf("Linha atualizada.\n");
}


void apagar_linha() {
    printf("\n                                                  Remover Linha \n");
    char n_linha_2[50];
    printf("Digite o nome da linha que deseja remover: ");
    fgets(n_linha_2, sizeof(n_linha_2), stdin);
    n_linha_2[strcspn(n_linha_2, "\n")] = '\0';

    // Procurar a linha pelo nome
    int indiceLinha = -1;
    for (int i = 0; i < num_linhas; i++) {
        if (strcmp(linhas[i].nome, n_linha_2) == 0) {
            indiceLinha = i;
            break;
        }
    }

    if (indiceLinha == -1) {
        printf("Linha %s nao encontrada.\n", n_linha_2);
    } else {
        // Remover a linha e reorganizar as linhas restantes
        for (int i = indiceLinha; i < num_linhas - 1; i++) {
            linhas[i] = linhas[i + 1];
        }
        num_linhas--;

        printf("Linha %s removida com sucesso.\n", n_linha_2);
    }
}


void ver_linhas() {
    limparEcra();

    // Se não existirem linhas registadas apresenta uma mensagem de erro
    if (num_linhas == 0) {
        printf("Nao existem linhas registadas.\n");
        return;
    }

    for (int i = 0; i < num_linhas; i++) {

        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("                                             Linha: %s\n\n", linhas[i].nome);
        printf("                                             Paragens:\n\n");


        for (int j = 0; j < linhas[i].num_paragens; j++) {
            printf("                                             Nome: %s\n", linhas[i].paragens[j].nome);
            printf("                                             Codigo: %s\n\n", linhas[i].codigo_paragens[j]);
        }

        printf("\n");
    }
}