#include "contatos.h"
#include <stdio.h>
#include <string.h>

int main() {
  funcao fs[] = {criar, deletar, listar, alterar, salvar, carregar};

  Contato contatos_pessoais[TOTAL];
  int pos_pessoais = 0;

  Contato contatos_trabalho[TOTAL];
  int pos_trabalho = 0;

  ERROS erro = fs[4](contatos, &pos);
    if(erro != OK){
      if(erro == ABRIR){
        printf("erro ao abrir o arquivo\n");
        pos = 0;
      } 
      else if(erro == FECHAR){
        printf("erro ao fechar o arquivo\n");
        pos = 0;
      }
      else if(erro == LER){
        printf("erro ao ler no arquivo\n");
        pos = 0;
      }
  }

   int opcao;
  
  int opcao;
  
  do {
    printf("\nMenu principal\n");
    printf("1 - Criar contato\n");
    printf("2 - Deletar contato\n");
    printf("3 - Listar contatos\n");
    printf("4 - Alterar dados do contato\n");
    printf("0 - Sair\n");
    printf("Entre com uma opcao: ");

    scanf("%d", &opcao);
    clearBuffer();
    printf("Opcao escolhida: %d\n", opcao);

    if (opcao == 1) {
      erro = criar(contatos_pessoais, contatos_trabalho, &pos_pessoais, &pos_trabalho);
      if (erro == MAX_CONTATOS) {
          printf("Máximo de contatos alcançado\n");
      } else if (erro == TIPO_INVALIDO) {
          printf("Número inválido\n");
      }
    } else if (opcao == 2) {
      erro = deletar(contatos_pessoais, contatos_trabalho, &pos_pessoais, &pos_trabalho);
      if (erro == SEM_CONTATOS) {
        printf("Sem contatos para deletar\n");
      } else if (erro == NAO_ENCONTRADO) {
          printf("Esse contato não existe\n");
      }
    } else if (opcao == 3) {
      erro = listar(contatos_pessoais, contatos_trabalho, &pos_pessoais, &pos_trabalho);
      if (erro == SEM_CONTATOS) {
        printf("Sem contatos para listar\n");
      }
    } else if (opcao == 4) {
      erro = alterar(contatos_pessoais, contatos_trabalho, &pos_pessoais, &pos_trabalho);
      if (erro == SEM_CONTATOS) {
          printf("Sem contatos para alterar\n");
      } else if (erro == NAO_ENCONTRADO) {
          printf("Esse contato não existe\n");
      }
    } else if (opcao == 0) {
        printf("Sair. . .\n");
      erro = salvar(contatos, &pos);
      if(erro == ABRIR)
        printf("erro ao abrir o arquivo\n");
      else if(erro == FECHAR)
        printf("erro ao fechar o arquivo\n");
      else if(erro == ESCREVER)
        printf("erro ao escrever no arquivo\n");
  } else {
      printf("opcao invalida");
    }
  } while (opcao != 0);
}
