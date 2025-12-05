#include <stdio.h>
#include <string.h>
#include "../include/structs.h"
#include "../include/cliente.h"
#include "../include/funcionario.h"
#include "../include/quarto.h"

void testar_cadastrar_cliente() {
    Cliente c;
    printf("== Cadastrar Cliente ==\n");
    printf("Codigo (int): "); scanf("%d%*c", &c.codigo);
    printf("Nome: "); fgets(c.nome, sizeof(c.nome), stdin); c.nome[strcspn(c.nome, "\n")] = '\0';
    printf("Endereco: "); fgets(c.endereco, sizeof(c.endereco), stdin); c.endereco[strcspn(c.endereco, "\n")] = '\0';
    printf("Telefone: "); fgets(c.telefone, sizeof(c.telefone), stdin); c.telefone[strcspn(c.telefone, "\n")] = '\0';
    c.pontos_fidelidade = 0;

    int r = cadastrar_cliente(c);
    if (r == 1) printf("Cliente cadastrado com sucesso.\n");
    else if (r == 0) printf("ERRO: codigo de cliente duplicado.\n");
    else printf("ERRO de I/O ao cadastrar cliente.\n");
}

void testar_cadastrar_funcionario() {
    Funcionario f;
    printf("== Cadastrar Funcionario ==\n");
    printf("Codigo (int): "); scanf("%d%*c", &f.codigo);
    printf("Nome: "); fgets(f.nome, sizeof(f.nome), stdin); f.nome[strcspn(f.nome, "\n")] = '\0';
    printf("Telefone: "); fgets(f.telefone, sizeof(f.telefone), stdin); f.telefone[strcspn(f.telefone, "\n")] = '\0';
    printf("Cargo: "); fgets(f.cargo, sizeof(f.cargo), stdin); f.cargo[strcspn(f.cargo, "\n")] = '\0';
    printf("Salario (float): "); scanf("%f%*c", &f.salario);

    int r = cadastrar_funcionario(f);
    if (r == 1) printf("Funcionario cadastrado com sucesso.\n");
    else if (r == 0) printf("ERRO: codigo de funcionario duplicado.\n");
    else printf("ERRO de I/O ao cadastrar funcionario.\n");
}

void testar_cadastrar_quarto() {
    Quarto q;
    printf("== Cadastrar Quarto ==\n");
    printf("Numero (int): "); scanf("%d%*c", &q.numero);
    printf("Qtd hospedes (int): "); scanf("%d%*c", &q.qtd_hospedes);
    printf("Valor diaria (float): "); scanf("%f%*c", &q.valor_diaria);
    // status é definido internamente
    int r = cadastrar_quarto(q);
    if (r == 1) printf("Quarto cadastrado com sucesso.\n");
    else if (r == 0) printf("ERRO: numero de quarto duplicado.\n");
    else printf("ERRO de I/O ao cadastrar quarto.\n");
}

int main() {
    while (1) {
        printf("\n===== TESTE SPRINT 2 =====\n");
        printf("1 - Cadastrar Cliente\n2 - Cadastrar Funcionario\n3 - Cadastrar Quarto\n0 - Sair\nEscolha: ");
        int op; if (scanf("%d%*c", &op)!=1) break;
        switch(op) {
            case 1: testar_cadastrar_cliente(); break;
            case 2: testar_cadastrar_funcionario(); break;
            case 3: testar_cadastrar_quarto(); break;
            case 0: return 0;
            default: printf("Opcao invalida.\n");
        }
    }
    return 0;
}
