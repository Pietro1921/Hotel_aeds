#ifndef DATA_H
#define DATA_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

int diferenca_dias(Data entrada, Data saida);

#endif 
