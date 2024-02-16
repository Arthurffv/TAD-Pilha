#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

void LerProduto(TProduto *Produto) {
  printf("Digite o codigo do produto:\n");
  fflush(stdin);
  scanf("%d", &Produto->codigo);
  printf("\nDigite o valor do produto:\n");
  fflush(stdin);
  scanf("%f", &Produto->preco);
  printf("\nDigite o nome do produto, ate 100 caracteres:\n");
  printf("FAVOR APERTAR O ESPAÇO ANTES DE DIGITAR QUALQUER STRING.\n");
  fflush(stdin);
  getchar();
  fgets(Produto->nome, 100, stdin);
  printf("\nDigite a descricao do produto, ate 200 caracteres:\n");
  printf("FAVOR APERTAR O ESPAÇO ANTES DE DIGITAR QUALQUER STRING.\n");
  fflush(stdin);
  getchar();
  fgets(Produto->descricao, sizeof(Produto->descricao), stdin);
  printf("\nDigite a quantidade de produtos:\n");
  fflush(stdin);
  scanf("%d", &Produto->quantidade);
}

void ImprimirProduto(TProduto produto) {
  printf("\nO codigo do produto solicitado: %d\n", produto.codigo);
  printf("O valor do produto solicitado, R$ %.2f\n", produto.preco);
  printf("O nome do produto solicitado e %s\n", produto.nome);
  printf("Descricao do produto: %s\n", produto.descricao);
  printf("Temos %d unidades desse produto\n", produto.quantidade);
}