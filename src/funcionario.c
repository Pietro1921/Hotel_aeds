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
