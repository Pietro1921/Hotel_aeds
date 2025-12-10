#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cliente.h"
#include "../include/funcionario.h"
#include "../include/quarto.h"
#include "../include/estadia.h"
#include "../include/estatisticas.h"
#include "../include/relatorios.h"

/* ======================== MENU CLIENTES ======================== */
void menu_clientes() {
    int op;
    do {
        printf("\n===== MENU CLIENTES =====\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Pesquisar Cliente\n");
        printf("0 - Voltar\n");
        printf("> ");
        scanf("%d%*c", &op);

        if (op == 1) {
            Cliente c;
            printf("Código: "); scanf("%d%*c", &c.codigo);
            printf("Nome: "); fgets(c.nome, 50, stdin); c.nome[strcspn(c.nome, "\n")] = 0;
            printf("Endereço: "); fgets(c.endereco, 100, stdin); c.endereco[strcspn(c.endereco, "\n")] = 0;
            printf("Telefone: "); fgets(c.telefone, 15, stdin); c.telefone[strcspn(c.telefone, "\n")] = 0;
            c.pontos_fidelidade = 0;

            int r = cadastrar_cliente(c);
            if (r == 1) printf("Cliente cadastrado!\n");
            else printf("ERRO: Código já existe.\n");
        }
        else if (op == 2) {
            pesquisar_cliente();
        }

    } while (op != 0);
}

/* ======================== MENU FUNCIONÁRIOS ======================== */
void menu_funcionarios() {
    int op;
    do {
        printf("\n===== MENU FUNCIONÁRIOS =====\n");
        printf("1 - Cadastrar Funcionário\n");
        printf("2 - Pesquisar Funcionário\n");
        printf("0 - Voltar\n");
        printf("> ");
        scanf("%d%*c", &op);

        if (op == 1) {
            Funcionario f;
            printf("Código: "); scanf("%d%*c", &f.codigo);
            printf("Nome: "); fgets(f.nome, 50, stdin); f.nome[strcspn(f.nome, "\n")] = 0;
            printf("Telefone: "); fgets(f.telefone, 15, stdin); f.telefone[strcspn(f.telefone, "\n")] = 0;
            printf("Cargo: "); fgets(f.cargo, 30, stdin); f.cargo[strcspn(f.cargo, "\n")] = 0;
            printf("Salário: "); scanf("%f%*c", &f.salario);

            int r = cadastrar_funcionario(f);
            if (r == 1) printf("Funcionário cadastrado!\n");
            else printf("ERRO: Código já existe.\n");
        }
        else if (op == 2) {
            pesquisar_funcionario();
        }

    } while (op != 0);
}

/* ======================== MENU QUARTOS ======================== */
void menu_quartos() {
    int op;
    do {
        printf("\n===== MENU QUARTOS =====\n");
        printf("1 - Cadastrar Quarto\n");
        printf("0 - Voltar\n");
        printf("> ");
        scanf("%d%*c", &op);

        if (op == 1) {
            Quarto q;
            printf("Número do quarto: "); scanf("%d%*c", &q.numero);
            printf("Qtd hóspedes: "); scanf("%d%*c", &q.qtd_hospedes);
            printf("Valor diária: "); scanf("%f%*c", &q.valor_diaria);

            int r = cadastrar_quarto(q);
            if (r == 1) printf("Quarto cadastrado!\n");
            else printf("ERRO: Quarto já existe.\n");
        }

    } while (op != 0);
}

/* ======================== MENU ESTADIAS ======================== */
void menu_estadias() {
    int op;
    do {
        printf("\n===== MENU ESTADIAS =====\n");
        printf("1 - Criar Estadia (Check-in)\n");
        printf("2 - Encerrar Estadia (Check-out)\n");
        printf("3 - Listar Todas as Estadias\n");
        printf("4 - Listar Estadias de um Cliente\n");
        printf("0 - Voltar\n");
        printf("> ");
        scanf("%d%*c", &op);

        if (op == 1) {
            Estadia e;
            printf("Código da Estadia: "); scanf("%d%*c", &e.codigo_estadia);
            printf("Código do Cliente: "); scanf("%d%*c", &e.cod_cliente);
            printf("Número do Quarto: "); scanf("%d%*c", &e.num_quarto);
            printf("Data Entrada (dd/mm/aaaa): "); 
            fgets(e.data_entrada, 11, stdin); 
            e.data_entrada[strcspn(e.data_entrada, "\n")] = 0;

            int r = criar_estadia(e);
            if (r == 1) printf("Estadia criada com sucesso!\n");
            else if (r == -1) printf("ERRO: Quarto ocupado.\n");
            else printf("ERRO: Código de estadia já existe.\n");
        }
        else if (op == 2) {
            int codigo;
            char data_saida[11];
            printf("Código da Estadia: "); scanf("%d%*c", &codigo);
            printf("Data Saída (dd/mm/aaaa): "); 
            fgets(data_saida, 11, stdin); 
            data_saida[strcspn(data_saida, "\n")] = 0;

            int r = encerrar_estadia(codigo, data_saida);
            if (r == 1) printf("Check-out realizado com sucesso!\n");
            else printf("ERRO: Estadia não encontrada.\n");
        }
        else if (op == 3) {
            listar_estadias();
        }
        else if (op == 4) {
            int codc;
            printf("Código do Cliente: "); scanf("%d%*c", &codc);
            listar_estadias_cliente(codc);
        }

    } while (op != 0);
}

/* ======================== MENU PRINCIPAL ======================== */
int main() {
    int op;
    do {
        printf("\n=========== SISTEMA HOTEL ===========\n");
        printf("1 - Clientes\n");
        printf("2 - Funcionários\n");
        printf("3 - Quartos\n");
        printf("4 - Estadias\n");
        printf("5 - Estatísticas do Sistema\n");   
        printf("6 - Relatórios\n");
        printf("0 - Sair\n");
        printf("> ");
        scanf("%d%*c", &op);

        if (op == 1) menu_clientes();
        else if (op == 2) menu_funcionarios();
        else if (op == 3) menu_quartos();
        else if (op == 4) menu_estadias();
        else if (op == 5) mostrar_estatisticas();  
        else if (op == 6) {
            gerar_relatorio_clientes();
            gerar_relatorio_funcionarios();
            gerar_relatorio_quartos();
            gerar_relatorio_estadias();
            gerar_relatorio_fidelidade();
            gerar_ranking_clientes();
            printf("Relatórios gerados na pasta /relatorios\n");
    }

    } while (op != 0);

    printf("Sistema encerrado.\n");
    return 0;
}