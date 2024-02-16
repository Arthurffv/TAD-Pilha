#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int codigo;
  float preco;
  char nome[100];
  char descricao[200];
  int quantidade;
} TProduto;

typedef struct celula {
  TProduto Item;
  struct celula *prox;
} TCelula;

typedef struct {
  char caractere;
} TElemento;

typedef struct {
  TElemento Item;
  struct celula *prox;
} TCelulaCaracter;

void LerProduto(TProduto *Produto);
void ImprimirProduto(TProduto produto);

#endif // UTIL_H_INCLUDED