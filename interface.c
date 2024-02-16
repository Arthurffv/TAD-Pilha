#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"

void MSG_MENU() {
  system("cls");
  printf(
      "\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
  printf("\n\n\t1. EMPILHAR");
  printf("  \n\t2. PESQUISAR");
  printf("  \n\t3. DESEMPILHAR");
  printf("  \n\t4. IMPRIMIR");
  printf("  \n\t5. INVERTER PILHA USANDO FILA");
  printf("  \n\t6. INVERTE PILHA USANDO DUAS PILHAS");
  printf("  \n\t7. INVERTE PILHA USANDO UMA PILHA");
  printf("  \n\t8. AVALIAR EXPRESSAO");
  printf("  \n\t9. TRADUTOR DE EXPRESSAO");
  printf("  \n\t10. SAIR");
}

void MENU(TPilha *Pilha01) {
  TProduto produto;
  int opcao = 0;
  int i;
  TProduto ImprimirProd;
  char Expressao[100];
  do {
    MSG_MENU();
    printf("\n\nDigite uma opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      LerProduto(&produto);
      Empilhar(produto, Pilha01);
      break;
    case 2:
      LerProduto(&produto);
      ImprimirProd = PesquisarPIlha(Pilha01, produto);
      printf("Produto encontrado: \n");
      ImprimirProduto(ImprimirProd);
      break;
    case 3:
      Desempilha(Pilha01, &produto);
      break;
    case 4:
      printf("Pilha 01.\n");
      PImprimir(Pilha01);
      break;
    case 5:
      InveterPilhaUsandoFila(Pilha01);
      break;
    case 6:
      InvertePilhaUsandoDuasPilhas(Pilha01);
      break;
    case 7:
      InvertePilhaUsandoUmaPilha(Pilha01);
      break;
    case 8:
      printf("Digite a expressao que deseja testar: \n");
      printf("FAVOR APERTAR O ESPAÇO ANTES DE DIGITAR QUALQUER STRING.\n");
      fflush(stdin);
      getchar();
      fgets(Expressao, 100, stdin);
      if (AvaliarExpressao(Expressao)) {
        printf("EXPRESSAO CORRETA.\n");
      } else {
        printf("EXPRESSAO INCORRETA.\n");
      }
      break;

    case 9:
      printf("Digite a expressao que deseja traduzir: \n");
      printf("FAVOR APERTAR O ESPAÇO ANTES DE DIGITAR QUALQUER STRING.\n");
      fflush(stdin);
      getchar();
      fgets(Expressao, 100, stdin);
      TradutorDeExpressao(Expressao);
      break;
    case 10:
      system("cls");
      printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
      system("PAUSE");
      break;

    default:
      system("cls");
      printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
      system("PAUSE");
    }
  } while (opcao != 10);
}
