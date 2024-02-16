#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Fila.h"

void FFVazia(TFila *Fila) {
  Fila->frente = (TCelula *)malloc(sizeof(TCelula));
  Fila->tras = Fila->frente;
  Fila->frente->prox = NULL;
  Fila->tamanho = 0;
}

int FVazia(TFila Fila) { return (Fila.frente == Fila.tras); }

void Enfileirar(TProduto x, TFila *Fila) {
  Fila->tras->prox = (TCelula *)malloc(sizeof(TCelula));
  Fila->tras = Fila->tras->prox;
  Fila->tras->Item = x;
  Fila->tras->prox = NULL;
  Fila->tamanho++;
}

void Desenfileirar(TFila *Fila, TProduto *Item) {
  TCelula *aux;
  if (!FVazia(*Fila)) {
    aux = Fila->frente->prox;
    Fila->frente->prox = aux->prox;
    *Item = aux->Item;
    free(aux);
    if (Fila->frente->prox == NULL)
      Fila->tras = Fila->frente;
    Fila->tamanho--;
  }
}

void LiberarFila(TFila *fila) {
  TProduto *Item;
  TCelula *aux;
  while (!FVazia(*fila)) {
    if (!FVazia(*fila)) {
      aux = fila->frente->prox;
      fila->frente->prox = aux->prox;
      *Item = aux->Item;
      free(aux);
      if (fila->frente->prox == NULL) {
        fila->tras = fila->frente;
      }
      (fila->tamanho)--;
    }
  }
  free(fila->frente);
}

void FImprimir(TFila *Fila) {
  TFila Aux;
  FFVazia(&Aux);
  TProduto ProdAux;
  while (Fila->frente->prox != NULL) {
    Desenfileirar(Fila, &ProdAux);
    ImprimirProduto(ProdAux);
    Enfileirar(ProdAux, &Aux);
  }
  while (Aux.frente->prox != NULL) {
    Desenfileirar(&Aux, &ProdAux);
    Enfileirar(ProdAux, Fila);
  }
  free(Aux.frente);
}