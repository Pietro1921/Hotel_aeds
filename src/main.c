#include <stdio.h>
#include "C:/Users/ifood/trabalho hotel descanso/include/structs.h"
#include "C:/Users/ifood/trabalho hotel descanso/include/persistencia.h"

Cliente clientes[100];
int qtdClientes = 0;

int main() {
    printf("=== Teste da Sprint 1 ===\n");

    // Carregar dados do arquivo
    ler_dados("data/clientes.bin", clientes, sizeof(Cliente), &qtdClientes);

    printf("Clientes carregados: %d\n", qtdClientes);

    // Adicionar um cliente novo
    Cliente c = { qtdClientes + 1, "Maria", "Rua A", "31999999999", 0 };
    clientes[qtdClientes++] = c;

    // Salvar de volta
    salvar_dados("data/clientes.bin", clientes, sizeof(Cliente), qtdClientes);

    printf("Novo cliente salvo!\n");

    // Mostrar todos para confirmar
    printf("\n--- Lista de Clientes ---\n");
    for (int i = 0; i < qtdClientes; i++) {
        printf("Código: %d | Nome: %s\n", clientes[i].codigo, clientes[i].nome);
    }

    return 0;
}
