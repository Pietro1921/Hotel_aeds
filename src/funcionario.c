#include <string.h>
#include <stdio.h>
#include "../include/funcionario.h"
#include "../include/persistencia.h"

#define ARQ_FUNCIONARIOS "data/funcionarios.bin"
#define MAX_FUNC 1000


int carregar_funcionarios(Funcionario *arr, int max, int *qtd) {
    if (!ler_dados(ARQ_FUNCIONARIOS, arr, sizeof(Funcionario), qtd)) {
        *qtd = 0;
        return 1;
    }
    if (*qtd > max) *qtd = max;
    return 1;
}

int cadastrar_funcionario(Funcionario f) {
    Funcionario lista[MAX_FUNC];
    int qtd = 0;
    if (!carregar_funcionarios(lista, MAX_FUNC, &qtd)) return -1;

    for (int i = 0; i < qtd; i++) {
        if (lista[i].codigo == f.codigo) return 0;
    }

    if (qtd >= MAX_FUNC) return -1;
    lista[qtd++] = f;

    if (!salvar_dados(ARQ_FUNCIONARIOS, lista, sizeof(Funcionario), qtd)) return -1;
    return 1;
}

// PB20 - PESQUISAR FUNCIONÁRIO
void pesquisar_funcionario() {
    Funcionario lista[1000];
    int qtd = 0;
    carregar_funcionarios(lista, 1000, &qtd);

    if (qtd == 0) {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }

    int opcao;
    printf("\nPesquisar funcionário por:\n");
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
                printf("\n--- Funcionário Encontrado ---\n");
                printf("Código: %d\n", lista[i].codigo);
                printf("Nome: %s\n", lista[i].nome);
                printf("Telefone: %s\n", lista[i].telefone);
                printf("Cargo: %s\n", lista[i].cargo);
                printf("Salário: %.2f\n", lista[i].salario);
                return;
            }
        }
        printf("Funcionário não encontrado.\n");
    }
    else if (opcao == 2) {
        char nome[50];
        printf("Nome (ou parte do nome): ");
        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = 0;

        int achou = 0;
        for (int i = 0; i < qtd; i++) {
            if (strstr(lista[i].nome, nome) != NULL) {
                printf("\n--- Funcionário Encontrado ---\n");
                printf("Código: %d\n", lista[i].codigo);
                printf("Nome: %s\n", lista[i].nome);
                printf("Telefone: %s\n", lista[i].telefone);
                printf("Cargo: %s\n", lista[i].cargo);
                printf("Salário: %.2f\n", lista[i].salario);
                achou = 1;
            }
        }

        if (!achou)
            printf("Nenhum funcionário corresponde à busca.\n");
    }
    else {
        printf("Opção inválida.\n");
    }
}
