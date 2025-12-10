#ifndef ESTADIA_H
#define ESTADIA_H

#include "structs.h"

int criar_estadia(Estadia e);
int encerrar_estadia(int codigo_estadia, char data_saida[]);
void listar_estadias();
int calcular_dias(char data1[], char data2[]); // calcula qtd_diarias a partir de strings

/* Lista todas as estadias de um cliente específico */
void listar_estadias_cliente(int cod_cliente);

#endif