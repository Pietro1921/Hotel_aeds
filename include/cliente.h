#ifndef CLIENTE_H
#define CLIENTE_H

#include "structs.h"

/* Cadastra um novo cliente no sistema */
int cadastrar_cliente(Cliente c);

int carregar_clientes(Cliente *arr, int max, int *qtd);

void pesquisar_cliente();

#endif