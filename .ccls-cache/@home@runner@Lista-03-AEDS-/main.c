#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

int main() {

  printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> POR FAVOR LEIA ANTES DE AVALIAR "
         "<<<<<<<<<<<<<<<<<<<<<<<<");
  printf("\nInfelizmente tive que manter o getchar antes de cada fgets, devido "
         "quando retirava estava simplismente"
         " ingnorando aquela parte do codigo (mesmo com o fflush), por isso a "
         "msg para apertar o espaço antes de digitar a string.\n");

  TPilha Pilha01;

  FPVazia(&Pilha01);
  PVazia(Pilha01);

  MENU(&Pilha01);

  LiberarPilha(&Pilha01);

  return 0;
}