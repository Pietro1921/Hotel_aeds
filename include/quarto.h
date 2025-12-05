#ifndef QUARTO_H
#define QUARTO_H

#include "structs.h"

/* Cadastra um novo quarto no sistema */
int cadastrar_quarto(Quarto q);
int carregar_quartos(Quarto *arr, int max, int *qtd);

#endif
