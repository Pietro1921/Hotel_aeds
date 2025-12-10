#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/estadia.h"
#include "../include/persistencia.h"
#include "../include/quarto.h"
#include "../include/cliente.h"

#define ARQ_ESTADIAS "data/estadias.bin"

//  CÁLCULO DE DIAS
int calcular_dias(char data1[], char data2[]) {
    int d1, m1, a1, d2, m2, a2;

    sscanf(data1, "%d/%d/%d", &d1, &m1, &a1);
    sscanf(data2, "%d/%d/%d", &d2, &m2, &a2);

    int dias1 = a1 * 365 + m1 * 30 + d1;
    int dias2 = a2 * 365 + m2 * 30 + d2;

    return dias2 - dias1;
}

//  CRIAR ESTADIA (CHECK-IN)
int criar_estadia(Estadia e) {
    Estadia lista[200];
    int qtd = 0;

    ler_dados(ARQ_ESTADIAS, lista, sizeof(Estadia), &qtd);

    // Verifica duplicidade
    for (int i = 0; i < qtd; i++) {
        if (lista[i].codigo_estadia == e.codigo_estadia) {
            return 0;
        }
    }

    // Verifica se o quarto está livre
    if (!quarto_disponivel(e.num_quarto)) {
        return -1;
    }

    lista[qtd] = e;
    lista[qtd].qtd_diarias = 0;
    lista[qtd].valor_total = 0;
    qtd++;

    salvar_dados(ARQ_ESTADIAS, lista, sizeof(Estadia), qtd);

    ocupar_quarto(e.num_quarto);

    return 1;
}

//  ENCERRAR ESTADIA (CHECK-OUT)
int encerrar_estadia(int codigo_estadia, char data_saida[]) {
    Estadia lista[200];
    int qtd = 0;

    ler_dados(ARQ_ESTADIAS, lista, sizeof(Estadia), &qtd);

    Cliente clientes[1000];
    int qtdClientes = 0;
    carregar_clientes(clientes, 1000, &qtdClientes);

    for (int i = 0; i < qtd; i++) {
        if (lista[i].codigo_estadia == codigo_estadia) {

            // Atualiza data de saída
            strcpy(lista[i].data_saida, data_saida);

            // Calcula diárias
            lista[i].qtd_diarias = calcular_dias(lista[i].data_entrada, data_saida);

            // Obtém valor diária do quarto
            float diaria = obter_valor_diaria(lista[i].num_quarto);

            // Calcula valor total
            lista[i].valor_total = lista[i].qtd_diarias * diaria;

            // Atualiza pontos do cliente (PB19)
            for (int c = 0; c < qtdClientes; c++) {
                if (clientes[c].codigo == lista[i].cod_cliente) {
                    clientes[c].pontos_fidelidade += (lista[i].qtd_diarias * 10);
                    break;
                }
            }

            // Salva cliente atualizado
            salvar_dados("data/clientes.bin", clientes, sizeof(Cliente), qtdClientes);

            // Salva estadia atualizada
            salvar_dados(ARQ_ESTADIAS, lista, sizeof(Estadia), qtd);

            // Libera o quarto
            desocupar_quarto(lista[i].num_quarto);

            return 1;
        }
    }

    return 0;
}

//  LISTAR ESTADIAS
void listar_estadias() {
    Estadia lista[200];
    int qtd = 0;

    if (!ler_dados(ARQ_ESTADIAS, lista, sizeof(Estadia), &qtd)) {
        printf("Nenhuma estadia encontrada.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("\n--- Estadia %d ---\n", lista[i].codigo_estadia);
        printf("Cliente: %d\n", lista[i].cod_cliente);
        printf("Quarto : %d\n", lista[i].num_quarto);
        printf("Entrada: %s\n", lista[i].data_entrada);

        if (lista[i].qtd_diarias > 0) {
            printf("Saída  : %s\n", lista[i].data_saida);
            printf("Diárias: %d\n", lista[i].qtd_diarias);
            printf("Valor Total: R$ %.2f\n", lista[i].valor_total);
        }
    }
}

// PB21 - LISTAR TODAS AS ESTADIAS DE UM CLIENTE
void listar_estadias_cliente(int cod_cliente) {
    Estadia lista[200];
    int qtd = 0;

    if (!ler_dados("data/estadias.bin", lista, sizeof(Estadia), &qtd)) {
        printf("Nenhuma estadia encontrada.\n");
        return;
    }

    int achou = 0;

    printf("\n=== Estadias do Cliente %d ===\n", cod_cliente);

    for (int i = 0; i < qtd; i++) {
        if (lista[i].cod_cliente == cod_cliente) {
            achou = 1;

            printf("\n--- Estadia %d ---\n", lista[i].codigo_estadia);
            printf("Quarto: %d\n", lista[i].num_quarto);
            printf("Entrada: %s\n", lista[i].data_entrada);

            if (lista[i].qtd_diarias > 0) {
                printf("Saída: %s\n", lista[i].data_saida);
                printf("Diárias: %d\n", lista[i].qtd_diarias);
                printf("Valor Total: R$ %.2f\n", lista[i].valor_total);
            } else {
                printf("Status: Estadia ainda aberta\n");
            }
        }
    }

    if (!achou)
        printf("Nenhuma estadia encontrada para este cliente.\n");
}
