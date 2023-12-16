//
// Created by João Mota on 16/04/2023.
//

#include "main.h"
#include "paragens.h"
#include "menu.h"
#include "linhas.h"

int main() {

    paragens_default();
    linhas_default();

    bool sair = false; // Variável para controlar a saída do loop principal
    int opcao;


    while (!sair) {
        limparEcra();
        menu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            // 1 - Paragens
            case 1:
                while (true) {
                    limparEcra();
                    paragens_menu();
                    scanf("%d", &opcao);
                    getchar();


                    switch (opcao) {
                        case 1:
                            registar_paragens(); // Registrar
                            getchar();
                            break;
                        case 2:
                            eliminar_paragens(); // Eliminar
                            getchar();
                            break;
                        case 3:
                            visualizar_paragens(); // Visualizar
                            getchar();
                            break;
                        case 4:
                            break; // Sair
                        default:
                            printf("Opção invalida.\n"); // Opção inválida
                            break;
                    }

                    // Se a opcao == 4 sai do menu
                    if (opcao == 4) {
                        break;
                    }
                }
                break;

                // 2 - Linhas
            case 2:
                while (true) {
                    limparEcra();
                    linhas_menu();
                    scanf("%d", &opcao);
                    getchar();

                    switch (opcao) {
                        case 1: {
                            char n_linha[100];
                            printf("Insira o nome da linha: ");
                            scanf(" %99[^\n]", n_linha); // Lê uma string até 99 caracteres (ignora o caractere de nova linha)
                            getchar();
                            adicionar_linha(n_linha); // Adiciona
                            break;
                        }
                        case 2:
                            atualizar_linha(); // Atualiza
                            getchar();
                            break;
                        case 3: {
                            char n_linha[100];
                            char n_paragem[100];
                            printf("Insira o nome da linha: ");
                            scanf("%99s", n_linha); // Lê uma string de até 99 caracteres (para a primeira palavra)
                            printf("Insira o nome da paragem: ");
                            scanf(" %99[^\n]", n_paragem); // Lê uma string de até 99 caracteres (para a segunda palavra, ignorando o caractere de nova linha)
                            getchar();
                            liga_paragem_linha(n_linha, n_paragem); // Adiciona
                            break;
                        }
                        case 4: {
                            char n_linha_2[50];
                            printf("Digite o nome da linha: ");
                            scanf("%49[^\n]", n_linha_2); // Lê uma string de até 49 caracteres (ignorando o caractere de nova linha)
                            getchar();
                            char paragem_info[50];
                            printf("Digite o nome da paragem: ");
                            scanf(" %49[^\n]", paragem_info); // Lê uma string de até 49 caracteres (ignorando o caractere de nova linha)
                            getchar();
                            desliga_paragem_linha(n_linha_2, paragem_info);
                            break;
                        }
                        case 5:
                            ver_linhas(); // Ver
                            getchar();
                            break;
                        case 6:
                            apagar_linha(); // Eliminar
                            getchar();
                            break;
                        default:
                            printf("Opçao invalida\n"); // Opção inválida
                            break;
                    }

                    // Se opcao == 7 volta ao menu principal
                    if (opcao == 7) {
                        break;
                    }
                }
                break;
                // 5 - Sair do programa
            case 3:
                sair = true; // Encerra o loop principal
                break;

            default:
                printf("Opçao invalida. Tente novamente.\n"); // Opção inválida
                break;
        }
    }

    printf("\nObrigado pela preferencia!\n");

    return 0;
}