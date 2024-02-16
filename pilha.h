#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include "Fila.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  TCelula *topo;
  TCelula *fundo;
  int tamanho;
} TPilha;

typedef struct {
  TCelulaCaracter *topo;
} TPilhaCaracter;

void FPVazia(TPilha *Pilha);
int PVazia(TPilha Pilha);
void Empilhar(TProduto x, TPilha *Pilha);
void Desempilha(TPilha *Pilha, TProduto *Item);
void LiberarPilha(TPilha *Pilha);
void PImprimir(TPilha *Pilha);
void InveterPilhaUsandoFila(TPilha *Pilha);
void InvertePilhaUsandoDuasPilhas(TPilha *Pilha);
void InvertePilhaUsandoUmaPilha(TPilha *Pilha);
TProduto PesquisarPIlha(TPilha *Pilha, TProduto x);
int AvaliarExpressao(char Expressao[100]);
void FPVaziaCaracter(TPilhaCaracter *Pilha);
int PVaziaCaracter(TPilhaCaracter Pilha);
void EmpilharCaracter(char c, TPilhaCaracter *Pilha);
char DesempilharCaracter(TPilhaCaracter *Pilha);
int OrdemDePrioridade(char operador);
void TradutorDeExpressao(char *expressaoInfixada);

#endif // PILHA_H_INCLUDED