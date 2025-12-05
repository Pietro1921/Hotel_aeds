#include <string.h>
#include <stdio.h>
#include "../include/quarto.h"
#include "../include/persistencia.h"

#define ARQ_QUARTOS "data/quartos.bin"
#define MAX_QUARTOS 500

/* Carrega todos os quartos em um array passado*/
int carregar_quartos(Quarto *arr, int max, int *qtd) {
    if (!ler_dados(ARQ_QUARTOS, arr, sizeof(Quarto), qtd)) {
        *qtd = 0;
        return 1;
    }
    if (*qtd > max) *qtd = max;
    return 1;
}

int cadastrar_quarto(Quarto q) {
    Quarto lista[MAX_QUARTOS];
    int qtd = 0;
    if (!carregar_quartos(lista, MAX_QUARTOS, &qtd)) return -1;

    for (int i = 0; i < qtd; i++) {
        if (lista[i].numero == q.numero) return 0;
    }

    strncpy(q.status, "desocupado", sizeof(q.status)-1);
    q.status[sizeof(q.status)-1] = '\0';

    if (qtd >= MAX_QUARTOS) return -1;
    lista[qtd++] = q;

    if (!salvar_dados(ARQ_QUARTOS, lista, sizeof(Quarto), qtd)) return -1;
    return 1;
}
