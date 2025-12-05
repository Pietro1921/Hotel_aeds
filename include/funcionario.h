#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "structs.h"

/* Cadastra um novo funcionário no sistema */
int cadastrar_funcionario(Funcionario f);
int carregar_funcionarios(Funcionario *arr, int max, int *qtd);

#endif
