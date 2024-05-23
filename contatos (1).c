#include <stdio.h>
#include <string.h>
#include "contatos.h"

ERROS criar(Contato contatos[], int *pos) {
    if (*pos >= TOTAL)
        return MAX_CONTATOS;

    printf("Entre com o nome do contato: ");
    fgets(contatos[*pos].nome, 100, stdin);
    contatos[*pos].nome[strcspn(contatos[*pos].nome, "\n")] = '\0';

    printf("Entre com o numero do contato (até 11 digitos): ");
    fgets(contatos[*pos].numero, 11, stdin);
    contatos[*pos].numero[strcspn(contatos[*pos].numero, "\n")] = '\0';

    *pos = *pos + 1;

    return OK;
}

ERROS deletar(Contato contatos[], int *pos) {
    if (*pos == 0)
        return SEM_CONTATOS;
    char numero_deletar[11];
    printf("Entre com o numero do contato a ser deletado: ");
    fgets(numero_deletar, 11, stdin);
    numero_deletar[strcspn(numero_deletar, "\n")] = '\0';
    int pos_deletar = -1;
    for (int i = 0; i < *pos; i++) {
        if (strcmp(contatos[i].numero, numero_deletar) == 0) {
            pos_deletar = i;
            break;
        }
    }
    if (pos_deletar == -1) {
        return NAO_ENCONTRADO;
    }
    for (int i = pos_deletar; i < *pos; i++) {
        strcpy(contatos[i].nome, contatos[i + 1].nome);
        strcpy(contatos[i].numero, contatos[i + 1].numero);
    }
    *pos = *pos - 1;
    return OK;
}

ERROS listar(Contato contatos[], int *pos) {
    if (pos == 0)
        return SEM_CONTATOS;

    for (int i = 0; i < *pos; i++) {
        printf("Contato: %s\t", contatos[i].nome);
        printf("Numero: %s\n", contatos[i].numero);
    }

    return OK;
}


ERROS salvar (Contato contatos[], int *pos) {
    FILE *f = fopen("contatos.bin", "wb");
    if (f == NULL)
        return ABRIR;

    int qtd = fwrite(contatos, TOTAL, sizeof(Contato), f);
    if (qtd == 0)
        return ESCREVER;

    qtd = fwrite(pos, 1, sizeof(int), f);
    if (qtd == 0)
        return ESCREVER;

    if (fclose(f))
        return FECHAR;

    return OK;

}

ERROS carregar(Contato contatos[], int *pos) {
    FILE *f = fopen("contatos.bin", "rb");
    if (f == NULL)
        return ABRIR;
    int qtd = fread(contatos, TOTAL, sizeof(Contato), f);
    if (qtd == 0)
        return LER;
    qtd = fread(pos, 1, sizeof(int), f);
    if (qtd == 0)
        return LER;
    if (fclose(f))
        return FECHAR;
    return OK;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}
