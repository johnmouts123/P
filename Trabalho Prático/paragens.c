#include "paragens.h"
#include "linhas.h"
#include "utils.h"


Paragem * paragens = NULL; // Array dinâmico paragens
int num_paragens = 0; // Contador para o número de paragens



// Obter código da paragem em função do nome
void codigo_paragem(char * codigo, char *paragem_info) {
    // Percorre todas as paragens
    for (int i = 0; i < num_paragens; i++) {
        // Se o nome da paragem atual é igual ao nome fornecido
        if (strcmp(paragens[i].nome, paragem_info) == 0) {
            // Copia o código da paragem para a string de saída e retorna
            strcpy(codigo, paragens[i].codigo);
            return;
        }
    }

    // Se a paragem não foi encontrada, a string fica vazia
    strcpy(codigo, "");
}


int paragem_existe(const char *nome) {
    for (int i = 0; i < num_paragens; i++) {
        if (strcmp(paragens[i].nome, nome) == 0) {
            return 1; // Retorna 1 se a paragem já existe
        }
    }
    return 0; // Retorna 0 se a paragem não existe
}

void registar_paragens() {
    char codigo[5];
    char nome[50];

    printf("\n\n");
    printf("Nome da paragem: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    // Verifica se já existe uma paragem com esse nome
    if (paragem_existe(nome)) {
        printf("Erro: Paragem com esse nome já existe.\n");
        return;
    }

    gerar_codigo(codigo);

    // Cria a nova paragem
    Paragem nova_paragem;
    strcpy(nova_paragem.nome, nome);
    strcpy(nova_paragem.codigo, codigo);
    nova_paragem.num_linhas = 0;


    num_paragens++; // Incrementa o número de paragens
    paragens = realloc(paragens, num_paragens * sizeof(Paragem));
    paragens[num_paragens - 1] = nova_paragem; // Adiciona a nova paragem ao final do array

    printf("Paragem registada com sucesso.\n");
}



void eliminar_paragens() {

    // Verifica se existem paragens
    if (num_paragens == 0) {
        printf("Erro: Nao existem paragens registadas.\n");
        return;
    }

    // Obtém o código da paragem a ser removida
    char codigo[10];
    printf("Codigo da paragem a eliminar: ");
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    // Procura a paragem pelo código
    int i_paragem = -1; // Indice de paragem
    for (int i = 0; i < num_paragens; i++) {
        // Se encontrou a paragem, guarda o seu índice
        if (strcmp(paragens[i].codigo, codigo) == 0) {
            i_paragem = i;
            break;
        }
    }

    // Se a paragem não foi encontrada, exibe uma mensagem de erro e retorna
    if (i_paragem == -1) {
        printf("Erro: Paragem com esse codigo nao encontrada.\n");
        return;
    }

    if (paragens[i_paragem].num_linhas > 0) {
        printf("Erro: A paragem esta associada a uma ou mais linhas. Nao pode ser removida.\n");
        return;
    }

    // Move todas as paragens para a esquerda ( começa no indice da que foi eliminada )
    for (int i = i_paragem; i < num_paragens - 1; i++) {
        paragens[i] = paragens[i + 1];
    }

    // Decrementa o número de paragens
    num_paragens--;

    printf("Paragem removida com sucesso.\n");
}



void paragens_default() {

    char *paragens_default[] = {
            "Cantanhede",
            "Figueira da Foz",
            "Bifurcacao de Lares",
            "Lourical",
            "Alfarelos",
            "Soure",
            "Pombal",
            "Coimbra-B",
            "Coimbra",
            "Portagem",
            "Polo III",
            "Condeixa-a-Nova",
            "Santa Apolonia",
            "Hospital Pediatrico",
            "Loja do Cidadao",
            "Quinta da Fonte"
    };

    // Calcula o número de paragens pré-definidas (tamanho total do array / tamanho de um único elemento)
    int num_paragensDefault = sizeof(paragens_default) / sizeof(paragens_default[0]);


    for (int i = 0; i < num_paragensDefault; i++) {

        int existe = 0;
        for (int j = 0; j < num_paragens; j++) {
            if (strcmp(paragens[j].nome, paragens_default[i]) == 0) {
                existe = 1;
                break;
            }
        }

        char codigo[5];
        gerar_codigo(codigo);

        // Cria a nova paragem
        Paragem nova_paragem;
        strcpy(nova_paragem.nome, paragens_default[i]);
        strcpy(nova_paragem.codigo, codigo);
        nova_paragem.num_linhas = 0;
        nova_paragem.linhas = NULL;

        // Adiciona a nova paragem ao array de paragens
        num_paragens++;
        paragens = realloc(paragens, num_paragens * sizeof(Paragem));
        paragens[num_paragens - 1] = nova_paragem;
    }
}


void visualizar_paragens() {
    limparEcra();
    if (num_paragens == 0) {
        printf("Nao existem paragens registadas.\n");
        return;
    }

    // Para cada paragem, exibe o nome, código e linhas associadas
    for (int i = 0; i < num_paragens; i++) {
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("                                             Nome: %s\n", paragens[i].nome);
        printf("                                             Codigo: %s\n", paragens[i].codigo);
        printf("                                             Linha:");

        int linhas_conectadas = 0; // Contador para o número de linhas associadas à paragem

        // Percorre todas as linhas para verificar se a paragem está associada
        for (int j = 0; j < num_linhas; j++) {
            Linha linha = linhas[j];

            // Verifica a que linha está associada
            for (int k = 0; k < linha.num_paragens; k++) {
                if (strcmp(linha.paragens[k].nome, paragens[i].nome) == 0) {
                    printf(" %s", linha.nome);
                    linhas_conectadas++;
                    break; // Sai do loop assim que for verificado
                }
            }
        }

        // Printf para caso a paragem não esteja associada a nenhuma linha
        if (linhas_conectadas == 0) {
            printf(" - ");
        }

        printf("\n\n");
    }
}