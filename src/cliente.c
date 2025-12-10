#include <string.h>
#include <stdio.h>
#include "../include/cliente.h"
#include "../include/persistencia.h"

#define ARQ_CLIENTES "data/clientes.bin"
#define MAX_CLIENTES 1000

/* Carrega todos os clientes em um array passado*/
int carregar_clientes(Cliente *arr, int max, int *qtd) {
    if (!ler_dados(ARQ_CLIENTES, arr, sizeof(Cliente), qtd)) {
        *qtd = 0;
        return 1;
    }
    if (*qtd > max) *qtd = max;
    return 1;
}

int cadastrar_cliente(Cliente c) {
    Cliente lista[MAX_CLIENTES];
    int qtd = 0;
    if (!carregar_clientes(lista, MAX_CLIENTES, &qtd)) return -1;

    for (int i = 0; i < qtd; i++) {
        if (lista[i].codigo == c.codigo) return 0; 
    }

    if (qtd >= MAX_CLIENTES) return -1;
    lista[qtd++] = c;

    if (!salvar_dados(ARQ_CLIENTES, lista, sizeof(Cliente), qtd)) return -1;
    return 1;
}

// PB20 - PESQUISAR CLIENTE
void pesquisar_cliente() {
    Cliente lista[1000];
    int qtd = 0;
    carregar_clientes(lista, 1000, &qtd);

    if (qtd == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    int opcao;
    printf("\nPesquisar cliente por:\n");
    printf("1 - Código\n");
    printf("2 - Nome\n");
    printf("> ");
    scanf("%d%*c", &opcao);

    if (opcao == 1) {
        int codigo;
        printf("Digite o código: ");
        scanf("%d%*c", &codigo);

        for (int i = 0; i < qtd; i++) {
            if (lista[i].codigo == codigo) {
                printf("\n--- Cliente Encontrado ---\n");
                printf("Código: %d\n", lista[i].codigo);
                printf("Nome: %s\n", lista[i].nome);
                printf("Endereço: %s\n", lista[i].endereco);
                printf("Telefone: %s\n", lista[i].telefone);
                printf("Pontos Fidelidade: %d\n", lista[i].pontos_fidelidade);
                return;
            }
        }
        printf("Cliente não encontrado.\n");
    }
    else if (opcao == 2) {
        char nome[50];
        printf("Nome (ou parte do nome): ");
        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = 0;

        int achou = 0;
        for (int i = 0; i < qtd; i++) {
            if (strstr(lista[i].nome, nome) != NULL) {
                printf("\n--- Cliente Encontrado ---\n");
                printf("Código: %d\n", lista[i].codigo);
                printf("Nome: %s\n", lista[i].nome);
                printf("Endereço: %s\n", lista[i].endereco);
                printf("Telefone: %s\n", lista[i].telefone);
                printf("Pontos Fidelidade: %d\n", lista[i].pontos_fidelidade);
                achou = 1;
            }
        }

        if (!achou)
            printf("Nenhum cliente corresponde à busca.\n");
    }
    else {
        printf("Opção inválida.\n");
    }
}