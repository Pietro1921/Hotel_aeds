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
