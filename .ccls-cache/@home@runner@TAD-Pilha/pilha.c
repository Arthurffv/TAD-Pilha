#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

void FPVazia(TPilha *Pilha) {
  Pilha->topo = (TCelula *)malloc(sizeof(TCelula));
  Pilha->fundo = Pilha->topo;
  Pilha->topo->prox = NULL;
  Pilha->tamanho = 0;
}

void FPVaziaCaracter(TPilhaCaracter *Pilha) { Pilha->topo = NULL; }

int PVazia(TPilha Pilha) { return (Pilha.topo == Pilha.fundo); }

int PVaziaCaracter(TPilhaCaracter Pilha) { return Pilha.topo == NULL; }

void Empilhar(TProduto x, TPilha *Pilha) {
  TCelula *Aux;
  Aux = (TCelula *)malloc(sizeof(TCelula));
  Pilha->topo->Item = x;
  Aux->prox = Pilha->topo;
  Pilha->topo = Aux;
  Pilha->tamanho++;
}

void EmpilharCaracter(char c, TPilhaCaracter *Pilha) {
  TCelulaCaracter *NovaCelula;
  NovaCelula = (TCelulaCaracter *)malloc(sizeof(TCelulaCaracter));
  NovaCelula->Item.caractere = c;
  NovaCelula->prox = Pilha->topo;
  Pilha->topo = NovaCelula;
}

void Desempilha(TPilha *Pilha, TProduto *Item) {
  TCelula *q;
  if (PVazia(*Pilha)) {
    printf("Erro: Pilha vazia!\n");
    return;
  }
  q = Pilha->topo;
  Pilha->topo = q->prox;
  *Item = q->prox->Item;
  free(q);
  Pilha->tamanho--;
}

char DesempilharCaracter(TPilhaCaracter *Pilha) {
  if (!PVaziaCaracter(*Pilha)) {
    TCelulaCaracter *Temp = Pilha->topo;
    char caractere = Temp->Item.caractere;
    Pilha->topo = Temp->prox;
    free(Temp);
    return caractere;
  } else {
    return '\0';
  }
}

void LiberarPilha(TPilha *Pilha) {
  TProduto ProdAux;
  while (Pilha->topo->prox != NULL) {
    Desempilha(Pilha, &ProdAux);
  }
  if (Pilha->topo == Pilha->fundo) {
    free(Pilha->topo);
  }
}

void PImprimir(TPilha *Pilha) {
  TProduto ProdAux;
  TPilha PilhaAux;
  FPVazia(&PilhaAux);
  while (Pilha->topo->prox != NULL) {
    Desempilha(Pilha, &ProdAux);
    Empilhar(ProdAux, &PilhaAux);
  }

  while (PilhaAux.topo->prox != NULL) {
    Desempilha(&PilhaAux, &ProdAux);
    ImprimirProduto(ProdAux);
    Empilhar(ProdAux, Pilha);
  }
  free(PilhaAux.topo);
}

void InveterPilhaUsandoFila(TPilha *Pilha) {
  TProduto ProdAux;
  TFila FilaAux;
  FFVazia(&FilaAux);
  FVazia(FilaAux);
  while (Pilha->topo->prox != NULL) {
    Desempilha(Pilha, &ProdAux);
    Enfileirar(ProdAux, &FilaAux);
  }
  while (FilaAux.frente->prox != NULL) {
    Desenfileirar(&FilaAux, &ProdAux);
    Empilhar(ProdAux, Pilha);
  }
}

void InvertePilhaUsandoDuasPilhas(TPilha *Pilha) {
  TPilha PilhaAux1, PilhaAux2;
  FPVazia(&PilhaAux1);
  FPVazia(&PilhaAux2);
  PVazia(PilhaAux1);
  PVazia(PilhaAux2);
  TProduto ProdAux;
  while (Pilha->topo->prox != NULL) {
    Desempilha(Pilha, &ProdAux);
    Empilhar(ProdAux, &PilhaAux1);
  }
  while (PilhaAux1.topo->prox != NULL) {
    Desempilha(&PilhaAux1, &ProdAux);
    Empilhar(ProdAux, &PilhaAux2);
  }
  while (PilhaAux2.topo->prox != NULL) {
    Desempilha(&PilhaAux2, &ProdAux);
    Empilhar(ProdAux, Pilha);
  }
}

void InvertePilhaUsandoUmaPilha(TPilha *Pilha) {
  TProduto ProdutoAux;
  TProduto Anterior;
  TPilha PilhaAux;
  FPVazia(&PilhaAux);
  int n = Pilha->tamanho;

  Desempilha(Pilha, &Anterior);
  while (!PVazia(*Pilha)) {
    Desempilha(Pilha, &ProdutoAux);
    Empilhar(ProdutoAux, &PilhaAux);
  }
  Empilhar(Anterior, Pilha);
  while (!PVazia(PilhaAux)) {
    Desempilha(&PilhaAux, &ProdutoAux);
    Empilhar(ProdutoAux, Pilha);
  }

  for (int j = 1; j < n; j++) {
    Desempilha(Pilha, &Anterior);
    for (int i = 1; i <= n - j; i++) {
      Desempilha(Pilha, &ProdutoAux);
      Empilhar(ProdutoAux, &PilhaAux);
    }

    Empilhar(Anterior, Pilha);
    while (!PVazia(PilhaAux)) {
      Desempilha(&PilhaAux, &ProdutoAux);
      Empilhar(ProdutoAux, Pilha);
    }
  }

  Desempilha(Pilha, &Anterior);
  while (!PVazia(*Pilha)) {
    Desempilha(Pilha, &ProdutoAux);
    Empilhar(ProdutoAux, &PilhaAux);
  }
  Empilhar(Anterior, Pilha);
  while (!PVazia(PilhaAux)) {
    Desempilha(&PilhaAux, &ProdutoAux);
    Empilhar(ProdutoAux, Pilha);
  }
}

TProduto PesquisarPIlha(TPilha *Pilha, TProduto x) {
  TProduto ProdAux;
  TPilha PilhaAux;
  FPVazia(&PilhaAux);
  TProduto Retorno;
  while (Pilha->topo->prox != NULL) {
    Desempilha(Pilha, &ProdAux);
    Empilhar(ProdAux, &PilhaAux);
  }

  while (PilhaAux.topo->prox != NULL) {
    Desempilha(&PilhaAux, &ProdAux);
    if (Pilha->topo->Item.codigo == x.codigo) {
      Retorno = ProdAux;
    }
    Empilhar(ProdAux, Pilha);
  }
  free(PilhaAux.topo);
  return Retorno;
}

int AvaliarExpressao(char Expressao[100]) {
  TPilha Pilha;
  FPVazia(&Pilha);
  PVazia(Pilha);
  int i = 0;
  TProduto Empilharexpressao;
  while (Expressao[i] != '\n') {
    if (Expressao[i] == '(' || Expressao[i] == '[' || Expressao[i] == '{') {
      Empilharexpressao.nome[0] = Expressao[i];
      Empilhar(Empilharexpressao, &Pilha);
    }
    if (Expressao[i] == ')' || Expressao[i] == ']' || Expressao[i] == '}') {
      Desempilha(&Pilha, &Empilharexpressao);
    }
    i++;
  }
  if (PVazia(Pilha)) {
    return 1;
  } else {
    return 0;
  }
}

int OrdemDePrioridade(char operador) {
  if (operador == '+' || operador == '-') {
    return 1;
  } else if (operador == '*' || operador == '/') {
    return 2;
  }
  return 0;
}

void TradutorDeExpressao(char *expressaoInfixada) {
  TPilhaCaracter Pilha;
  FPVaziaCaracter(&Pilha);

  printf("\nExpressao Pós-fixada: \n");
  for (int i = 0; expressaoInfixada[i] != '\0'; i++) {
    char caractere = expressaoInfixada[i];

    if (caractere >= 'A' && caractere <= 'Z') {
      printf("%c", caractere);
    } else if (caractere == '(') {
      EmpilharCaracter(caractere, &Pilha);
    } else if (caractere == ')') {
      char topo;
      while ((topo = DesempilharCaracter(&Pilha)) != '(') {
        printf("%c", topo);
      }
    } else {
      while (!PVaziaCaracter(Pilha) &&
             OrdemDePrioridade(Pilha.topo->Item.caractere) >=
                 OrdemDePrioridade(caractere)) {
        printf("%c", DesempilharCaracter(&Pilha));
      }
      EmpilharCaracter(caractere, &Pilha);
    }
  }

  while (!PVaziaCaracter(Pilha)) {
    printf("%c", DesempilharCaracter(&Pilha));
  }

  printf("\n");
}