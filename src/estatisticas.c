#include <stdio.h>
#include "../include/estatisticas.h"
#include "../include/structs.h"
#include "../include/persistencia.h"

#define ARQ_CLIENTES      "data/clientes.bin"
#define ARQ_FUNCIONARIOS  "data/funcionarios.bin"
#define ARQ_QUARTOS       "data/quartos.bin"
#define ARQ_ESTADIAS      "data/estadias.bin"

// ---------- FUNÇÕES INTERNAS ---------- //

int total_clientes() {
    Cliente lista[1000];
    int qtd = 0;
    ler_dados(ARQ_CLIENTES, lista, sizeof(Cliente), &qtd);
    return qtd;
}

int total_funcionarios() {
    Funcionario lista[1000];
    int qtd = 0;
    ler_dados(ARQ_FUNCIONARIOS, lista, sizeof(Funcionario), &qtd);
    return qtd;
}

int total_quartos() {
    Quarto lista[1000];
    int qtd = 0;
    ler_dados(ARQ_QUARTOS, lista, sizeof(Quarto), &qtd);
    return qtd;
}

int total_estadias() {
    Estadia lista[1000];
    int qtd = 0;
    ler_dados(ARQ_ESTADIAS, lista, sizeof(Estadia), &qtd);
    return qtd;
}

// ---------- RELATÓRIO COMPLETO ---------- //

void mostrar_estatisticas() {
    int c = total_clientes();
    int f = total_funcionarios();
    int q = total_quartos();
    int e = total_estadias();

    printf("\n========= RELATÓRIO DE ESTATÍSTICAS =========\n");
    printf("Total de Clientes     : %d\n", c);
    printf("Total de Funcionários : %d\n", f);
    printf("Total de Quartos      : %d\n", q);
    printf("Total de Estadias     : %d\n", e);

    printf("---------------------------------------------\n");
    printf("Sistema funcionando normalmente.\n");
    printf("=============================================\n\n");
}
