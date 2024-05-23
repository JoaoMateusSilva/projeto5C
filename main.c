#include <stdio.h>
#include <string.h>
#include "contatos.h"

int main(){
  funcao fs[] = {criar, deletar, listar, salvar, carregar};

  Contato contatos[TOTAL];

  int pos;

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
  
  do {
    printf("\nMenu principal\n");
    printf("1 - Criar contato\n");
    printf("2 - Deletar contato\n");
    printf("3 - Listar contatos\n");
    printf("0 - Sair\n");
   
    printf("Entre com uma opcao: ");
    int i = scanf("%d", &opcao);
    clearBuffer();
    
    printf("Opcao escolhida: %d\n", opcao);
    
    if (opcao == 1) {
      erro = criar(contatos, &pos);
      if(erro == MAX_CONTATOS)
        printf("maximo de contatos alcancadas\n");
      else if(erro == NUMERO_INVALIDO)
        printf("numero invalido\n");
  } else if (opcao == 2) {
      erro = deletar(contatos, &pos);
      if(erro == SEM_CONTATOS)
        printf("sem contatos para deletar\n");
      else if(erro == NAO_ENCONTRADO)
        printf("esse c nao existe\n");
  } else if (opcao == 3) {
      erro = listar(contatos, &pos);
      if(erro == SEM_CONTATOS)
        printf("sem contatos para listar\n");
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

  ERROS errosalvar = fs[3](contatos, &pos);
    if(erro == ABRIR)
      printf("erro ao abrir o arquivo\n");
    else if(erro == FECHAR)
      printf("erro ao fechar o arquivo\n");
    else if(erro == ESCREVER)
      printf("erro ao escrever no arquivo\n");
}
