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
int tamanho(LISTA *l);
void exibirLista(LISTA *l);


int main() {
  LISTA l;

  inicializarLista(&l);

  printf("\n\n tamanho da lista: %d\n\n", tamanho(&l));


  exibirLista(&l);

  return 0;
}

void inicializarLista(LISTA *l) {
  l->nroElem = 0;
}

int tamanho(LISTA *l) {
  return l->nroElem;
}

void exibirLista(LISTA *l) {
  int i, fim = tamanho(l);
  printf("Lista: \" ");
  for(i = 0; i < fim; i++) 
    printf("%d%c", l->A[i].chave , (i< fim-1)? ',':' ');
  printf("\"\n");
}