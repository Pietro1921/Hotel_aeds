#include <stdio.h>
#include <string.h>
#include "../include/relatorios.h"
#include "../include/structs.h"
#include "../include/persistencia.h"

#define ARQ_CLIENTES "data/clientes.bin"
#define ARQ_FUNCIONARIOS "data/funcionarios.bin"
#define ARQ_QUARTOS "data/quartos.bin"
#define ARQ_ESTADIAS "data/estadias.bin"

/* ================= RELATÓRIOS SIMPLES ================= */

void gerar_relatorio_clientes() {
    Cliente c[1000];
    int qtd = 0;
    ler_dados(ARQ_CLIENTES, c, sizeof(Cliente), &qtd);

    FILE *f = fopen("relatorios/clientes.txt", "w");
    if (!f) return;

    for (int i = 0; i < qtd; i++) {
        fprintf(f, "Codigo: %d\nNome: %s\nTelefone: %s\nPontos: %d\n\n",
                c[i].codigo, c[i].nome, c[i].telefone, c[i].pontos_fidelidade);
    }
    fclose(f);
}

void gerar_relatorio_funcionarios() {
    Funcionario f[1000];
    int qtd = 0;
    ler_dados(ARQ_FUNCIONARIOS, f, sizeof(Funcionario), &qtd);

    FILE *arq = fopen("relatorios/funcionarios.txt", "w");
    if (!arq) return;

    for (int i = 0; i < qtd; i++) {
        fprintf(arq, "Codigo: %d\nNome: %s\nCargo: %s\nSalario: %.2f\n\n",
                f[i].codigo, f[i].nome, f[i].cargo, f[i].salario);
    }
    fclose(arq);
}

void gerar_relatorio_quartos() {
    Quarto q[1000];
    int qtd = 0;
    ler_dados(ARQ_QUARTOS, q, sizeof(Quarto), &qtd);

    FILE *f = fopen("relatorios/quartos.txt", "w");
    if (!f) return;

    for (int i = 0; i < qtd; i++) {
        fprintf(f, "Quarto: %d\nHospedes: %d\nDiaria: %.2f\nStatus: %s\n\n",
                q[i].numero, q[i].qtd_hospedes, q[i].valor_diaria, q[i].status);
    }
    fclose(f);
}

void gerar_relatorio_estadias() {
    Estadia e[1000];
    int qtd = 0;
    ler_dados(ARQ_ESTADIAS, e, sizeof(Estadia), &qtd);

    FILE *f = fopen("relatorios/estadias.txt", "w");
    if (!f) return;

    for (int i = 0; i < qtd; i++) {
        fprintf(f,
            "Estadia: %d\nCliente: %d\nQuarto: %d\nEntrada: %s\nSaida: %s\nValor: %.2f\n\n",
            e[i].codigo_estadia, e[i].cod_cliente, e[i].num_quarto,
            e[i].data_entrada, e[i].data_saida, e[i].valor_total);
    }
    fclose(f);
}

/* ================= FIDELIDADE + RANKING ================= */

void gerar_relatorio_fidelidade() {
    Cliente c[1000];
    Estadia e[1000];
    int qc = 0, qe = 0;

    ler_dados(ARQ_CLIENTES, c, sizeof(Cliente), &qc);
    ler_dados(ARQ_ESTADIAS, e, sizeof(Estadia), &qe);

    FILE *f = fopen("relatorios/fidelidade.txt", "w");
    if (!f) return;

    for (int i = 0; i < qc; i++) {
        int qtdEst = 0;
        float total = 0;

        for (int j = 0; j < qe; j++) {
            if (e[j].cod_cliente == c[i].codigo) {
                qtdEst++;
                total += e[j].valor_total;
            }
        }

        fprintf(f, "Cliente: %s\nPontos: %d\nEstadias: %d\nTotal Gasto: %.2f\n\n",
                c[i].nome, c[i].pontos_fidelidade, qtdEst, total);
    }
    fclose(f);
}

void gerar_ranking_clientes() {
    Cliente c[1000];
    int qtd = 0;
    ler_dados(ARQ_CLIENTES, c, sizeof(Cliente), &qtd);

    for (int i = 0; i < qtd - 1; i++) {
        for (int j = 0; j < qtd - 1; j++) {
            if (c[j].pontos_fidelidade < c[j + 1].pontos_fidelidade) {
                Cliente temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }

    FILE *f = fopen("relatorios/ranking.txt", "w");
    if (!f) return;

    for (int i = 0; i < qtd && i < 10; i++) {
        fprintf(f, "%dº %s - %d pontos\n",
                i + 1, c[i].nome, c[i].pontos_fidelidade);
    }
    fclose(f);
}