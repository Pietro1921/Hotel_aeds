#ifndef QUARTO_H
#define QUARTO_H

#include "structs.h"

int cadastrar_quarto(Quarto q);

int quarto_disponivel(int numero);
void ocupar_quarto(int numero);
void desocupar_quarto(int numero);
float obter_valor_diaria(int numero);

#endif
