#ifndef CLIENTE_H
#define CLIENTE_H

#include "structs.h"

/* Cadastra um novo cliente no sistema */
int cadastrar_cliente(Cliente c);

/* Carrega todos os clientes em um array passado (utilitário) */
int carregar_clientes(Cliente *arr, int max, int *qtd);

#endif
