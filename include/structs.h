#ifndef STRUCTS_H
#define STRUCTS_H

// Definição das estruturas utilizadas no sistema de gerenciamento hoteleiro
typedef struct {
    int codigo;
    char nome[50];
    char endereco[100];
    char telefone[15];
    int pontos_fidelidade;
} Cliente;

// Estrutura para representar um funcionário do hotel
typedef struct {
    int codigo;
    char nome[50];
    char telefone[15];
    char cargo[30];
    float salario;
} Funcionario;

// Estrutura para representar um quarto do hotel
typedef struct {
    int numero;
    int qtd_hospedes;
    float valor_diaria;
    char status[15]; 
} Quarto;

// Estrutura para representar uma estadia no hotel
typedef struct {
    int codigo_estadia;
    char data_entrada[11];
    char data_saida[11];
    int qtd_diarias;
    int cod_cliente;
    int num_quarto;
} Estadia;

#endif