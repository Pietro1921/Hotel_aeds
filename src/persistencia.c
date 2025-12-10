#include "../include/persistencia.h"

// Funções para salvar e ler dados binários de arquivos
int salvar_dados(const char *arquivo, const void *dados, size_t tam, int qtd) {
    FILE *fp = fopen(arquivo, "wb");
    if (!fp) return 0;

    fwrite(dados, tam, qtd, fp);
    fclose(fp);
    return 1;
}

int ler_dados(const char *arquivo, void *destino, size_t tam, int *qtd) {
    FILE *fp = fopen(arquivo, "rb");
    if (!fp) {
        *qtd = 0;
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long tamanho = ftell(fp);
    rewind(fp);

    *qtd = tamanho / tam;

    fread(destino, tam, *qtd, fp);
    fclose(fp);

    return 1;
}
