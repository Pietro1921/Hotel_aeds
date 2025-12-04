#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <stdio.h>

// Funções para salvar e ler dados binários de arquivos
int salvar_dados(const char *arquivo, const void *dados, size_t tam, int qtd);
int ler_dados(const char *arquivo, void *destino, size_t tam, int *qtd);

#endif