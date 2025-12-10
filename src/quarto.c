#include <string.h>
#include <stdio.h>
#include "../include/quarto.h"
#include "../include/persistencia.h"

#define ARQ_QUARTOS "data/quartos.bin"

/* ===================== FUNÇÕES INTERNAS ===================== */

static void carregar(Quarto lista[], int *qtd) {
    ler_dados(ARQ_QUARTOS, lista, sizeof(Quarto), qtd);
}

static void salvar(Quarto lista[], int qtd) {
    salvar_dados(ARQ_QUARTOS, lista, sizeof(Quarto), qtd);
}

/* ===================== CADASTRO DE QUARTO ===================== */

int cadastrar_quarto(Quarto q) {
    Quarto lista[200];
    int qtd = 0;

    carregar(lista, &qtd);

    // Verifica duplicidade
    for (int i = 0; i < qtd; i++) {
        if (lista[i].numero == q.numero) {
            return 0; // quarto já existe
        }
    }

    // Inicializa status
    strcpy(q.status, "desocupado");

    lista[qtd] = q;
    qtd++;

    salvar(lista, qtd);
    return 1;
}

/* ===================== DISPONIBILIDADE ===================== */

int quarto_disponivel(int numero) {
    Quarto lista[200];
    int qtd = 0;

    carregar(lista, &qtd);

    for (int i = 0; i < qtd; i++) {
        if (lista[i].numero == numero) {
            return strcmp(lista[i].status, "desocupado") == 0;
        }
    }

    return 0; // quarto não encontrado ou ocupado
}

/* ===================== OCUPAR / DESOCUPAR ===================== */

void ocupar_quarto(int numero) {
    Quarto lista[200];
    int qtd = 0;

    carregar(lista, &qtd);

    for (int i = 0; i < qtd; i++) {
        if (lista[i].numero == numero) {
            strcpy(lista[i].status, "ocupado");
            salvar(lista, qtd);
            return;
        }
    }
}

void desocupar_quarto(int numero) {
    Quarto lista[200];
    int qtd = 0;

    carregar(lista, &qtd);

    for (int i = 0; i < qtd; i++) {
        if (lista[i].numero == numero) {
            strcpy(lista[i].status, "desocupado");
            salvar(lista, qtd);
            return;
        }
    }
}

/* ===================== VALOR DA DIÁRIA ===================== */

float obter_valor_diaria(int numero) {
    Quarto lista[200];
    int qtd = 0;

    carregar(lista, &qtd);

    for (int i = 0; i < qtd; i++) {
        if (lista[i].numero == numero) {
            return lista[i].valor_diaria;
        }
    }

    return -1; // quarto não encontrado
}
