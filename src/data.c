#include "../include/data.h"

int diferenca_dias(Data entrada, Data saida) {
    int diasEntrada = entrada.ano*365 + entrada.mes*30 + entrada.dia;
    int diasSaida   = saida.ano*365   + saida.mes*30   + saida.dia;

    return diasSaida - diasEntrada;
}

