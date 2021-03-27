#include <stdio.h>
#define MAX 50

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct {
  REGISTRO A[MAX];
  int nroElem;
} LISTA;

void inicializarLista(LISTA *l);

int main() {
  LISTA l;

  inicializarLista(&l);


  return 0;
}

void inicializarLista(LISTA *l) {
  l->nroElem = 0;
}