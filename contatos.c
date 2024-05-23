#include "contatos.h"
#include <stdio.h>
#include <string.h>

int validar_email(char email[]) {
  int i, at = 0, dot = 0;
  for (i = 0; email[i] != '\0'; i++) {
    if (email[i] == '@') {
      at++;
    } else if (email[i] == '.') {
      dot++;
    }
  }
  if (at == 1 && dot >= 1)
    return 1;
  else
    return 0;
}

int validar_numero(char numero[]) {
  for (int i = 0; numero[i] != '\0'; i++) {
    if (!(numero[i] >= '0' && numero[i] <= '9')) {
      return 0;
    }
  }
  return 1;
}

ERROS criar(Contato contatos_pessoais[], Contato contatos_trabalho[],int *pos_pessoais, int *pos_trabalho) {

  if (*pos_pessoais >= TOTAL || *pos_trabalho >= TOTAL)
    return MAX_CONTATOS;

  char tipo_contato[10];

  printf("Entre com o tipo do contato (pessoal ou trabalho): ");
  fgets(tipo_contato, 10, stdin);
  tipo_contato[strcspn(tipo_contato, "\n")] = '\0';

  if (strcmp(tipo_contato, "pessoal") == 0) {

    printf("Entre com o nome do contato pessoal: ");
    fgets(contatos_pessoais[*pos_pessoais].nome, 100, stdin);
    contatos_pessoais[*pos_pessoais].nome[strcspn(contatos_pessoais[*pos_pessoais].nome, "\n")] = '\0';

    printf("Entre com o numero do contato pessoal (até 11 digitos): ");
    fgets(contatos_pessoais[*pos_pessoais].numero, 11, stdin);
    contatos_pessoais[*pos_pessoais].numero[strcspn(contatos_pessoais[*pos_pessoais].numero, "\n")] = '\0';

    do {

      printf("Entre com o email do contato pessoal: ");
      fgets(contatos_pessoais[*pos_pessoais].email, 100, stdin);
      contatos_pessoais[*pos_pessoais].email[strcspn(contatos_pessoais[*pos_pessoais].email, "\n")] = '\0';

    } while (!validar_email(contatos_pessoais[*pos_pessoais].email));
    (*pos_pessoais)++;
  } else if (strcmp(tipo_contato, "trabalho") == 0) {

    printf("Entre com o nome do contato de trabalho: ");
    fgets(contatos_trabalho[*pos_trabalho].nome, 100, stdin);
    contatos_trabalho[*pos_trabalho].nome[strcspn(contatos_trabalho[*pos_trabalho].nome, "\n")] = '\0';

    printf("Entre com o numero do contato de trabalho (até 11 digitos): ");
    fgets(contatos_trabalho[*pos_trabalho].numero, 11, stdin);
    contatos_trabalho[*pos_trabalho]
        .numero[strcspn(contatos_trabalho[*pos_trabalho].numero, "\n")] = '\0';
    do {
      printf("Entre com o email do contato de trabalho: ");
      fgets(contatos_trabalho[*pos_trabalho].email, 100, stdin);
      contatos_trabalho[*pos_trabalho].email[strcspn(contatos_trabalho[*pos_trabalho].email, "\n")] = '\0';

    } while (!validar_email(contatos_trabalho[*pos_trabalho].email));
    (*pos_trabalho)++;
  } else {
    return TIPO_INVALIDO;
  }
  for (int i = 0; i < *pos_pessoais; i++) {
    if (strcmp(contatos_pessoais[i].numero,
               contatos_pessoais[*pos_pessoais - 1].numero) == 0) {
      return NUMERO_EXISTENTE;
    }
  }
  for (int i = 0; i < *pos_trabalho; i++) {
    if (strcmp(contatos_trabalho[i].numero,
               contatos_pessoais[*pos_pessoais - 1].numero) == 0) {
      return NUMERO_EXISTENTE;
    }
  }
  return OK;
}

ERROS deletar(Contato contatos_pessoais[], Contato contatos_trabalho[],int *pos_pessoais, int *pos_trabalho) {

  char numero_deletar[11];

  printf("Entre com o numero do contato a ser deletado: ");
  fgets(numero_deletar, 11, stdin);
  numero_deletar[strcspn(numero_deletar, "\n")] = '\0';

  for (int i = 0; i < *pos_pessoais; i++) {
    if (strcmp(contatos_pessoais[i].numero, numero_deletar) == 0) {
      for (int j = i; j < *pos_pessoais; j++) {
        strcpy(contatos_pessoais[j].nome, contatos_pessoais[j + 1].nome);
        strcpy(contatos_pessoais[j].numero, contatos_pessoais[j + 1].numero);
        strcpy(contatos_pessoais[j].email, contatos_pessoais[j + 1].email);
      }
      (*pos_pessoais)--;
      return OK;
    }
  }
  for (int i = 0; i < *pos_trabalho; i++) {
    if (strcmp(contatos_trabalho[i].numero, numero_deletar) == 0) {
      for (int j = i; j < *pos_trabalho; j++) {
        strcpy(contatos_trabalho[j].nome, contatos_trabalho[j + 1].nome);
        strcpy(contatos_trabalho[j].numero, contatos_trabalho[j + 1].numero);
        strcpy(contatos_trabalho[j].email, contatos_trabalho[j + 1].email);
      }
      (*pos_trabalho)--;
      return OK;
    }
  }
  return NAO_ENCONTRADO;
}

ERROS listar(Contato contatos_pessoais[], Contato contatos_trabalho[],int *pos_pessoais, int *pos_trabalho) {
  if (pos_pessoais == 0 && pos_trabalho == 0)
    return SEM_CONTATOS;

  printf("Contatos Pessoais:\n");
  for (int i = 0; i < *pos_pessoais; i++) {
    printf("Nome: %s\t", contatos_pessoais[i].nome);
    printf("numero: %s\t", contatos_pessoais[i].numero);
    printf("Email: %s\n", contatos_pessoais[i].email);
  }

  printf("\nContatos de Trabalho:\n");
  for (int i = 0; i < *pos_trabalho; i++) {
    printf("Nome: %s\t", contatos_trabalho[i].nome);
    printf("numero: %s\t", contatos_trabalho[i].numero);
    printf("Email: %s\n", contatos_trabalho[i].email);
  }
  return OK;
}

ERROS alterar(Contato contatos_pessoais[], Contato contatos_trabalho[], int *pos_pessoais, int *pos_trabalho) {
  char numero_alterar[11];

  printf("Entre com o numero do contato a ser alterado: ");
  fgets(numero_alterar, 11, stdin);
  numero_alterar[strcspn(numero_alterar, "\n")] = '\0';

  char tipo_contato[10];

  printf("Entre com o tipo do contato a ser alterado (pessoal ou trabalho): ");
  fgets(tipo_contato, 10, stdin);
  tipo_contato[strcspn(tipo_contato, "\n")] = '\0';

  if (strcmp(tipo_contato, "pessoal") == 0) {
    
    for (int i = 0; i < *pos_pessoais; i++) {
      
      if (strcmp(contatos_pessoais[i].numero, numero_alterar) == 0) {
        printf("Entre com o novo nome do contato pessoal: ");
        fgets(contatos_pessoais[i].nome, 100, stdin);
        contatos_pessoais[i].nome[strcspn(contatos_pessoais[i].nome, "\n")] = '\0';
        
        do {
          printf("Entre com o novo numero do contato pessoal (até 11 digitos): ");
          fgets(contatos_pessoais[i].numero, 11, stdin);
          contatos_pessoais[i].numero[strcspn(contatos_pessoais[i].numero, "\n")] = '\0';
        } while (!validar_numero(contatos_pessoais[i].numero));
        do {
          printf("Entre com o novo email do contato pessoal: ");
          fgets(contatos_pessoais[i].email, 100, stdin);
          contatos_pessoais[i].email[strcspn(contatos_pessoais[i].email, "\n")] = '\0';
        } while (!validar_email(contatos_pessoais[i].email));
        return OK;
      }
    }
  } else if (strcmp(tipo_contato, "trabalho") == 0) {
    for (int i = 0; i < *pos_trabalho; i++) {
      if (strcmp(contatos_trabalho[i].numero, numero_alterar) == 0) {

        printf("Entre com o novo nome do contato de trabalho: ");
        fgets(contatos_trabalho[i].nome, 100, stdin);
        contatos_trabalho[i].nome[strcspn(contatos_trabalho[i].nome, "\n")] = '\0';

        do {

          printf("Entre com o novo numero do contato de trabalho (até 11 digitos): ");
          fgets(contatos_trabalho[i].numero, 11, stdin);
          contatos_trabalho[i].numero[strcspn(contatos_trabalho[i].numero, "\n")] = '\0';

        } while (!validar_numero(contatos_trabalho[i].numero));
        do {

          printf("Entre com o novo email do contato de trabalho: ");
          fgets(contatos_trabalho[i].email, 100, stdin);
          contatos_trabalho[i].email[strcspn(contatos_trabalho[i].email, "\n")] = '\0';

        } while (!validar_email(contatos_trabalho[i].email));
        return OK;
      }
    }
      for (int i = 0; i < *pos_pessoais; i++) {
          if (strcmp(contatos_pessoais[i].numero, numero_alterar) == 0) {
              return NUMERO_EXISTENTE;
          }
      }
      for (int i = 0; i < *pos_trabalho; i++) {
          if (strcmp(contatos_trabalho[i].numero, numero_alterar) == 0) {
              return NUMERO_EXISTENTE;
          }
      }
  } else {
    return TIPO_INVALIDO;
  }
  return NAO_ENCONTRADO;
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
