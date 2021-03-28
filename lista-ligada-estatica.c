#include <stdio.h>
#define MAX 50
#define INVALIDO -1

typedef int TIPOCHAVE;

typedef struct
{
  TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
  REGISTRO reg;
  int prox;
} ELEMENTO;

typedef struct
{
  ELEMENTO A[MAX];
  int inicio;
  int dispo;
} LISTA;

void inicializarLista(LISTA *l);

int main()
{

  return 0;
}

void inicializarLista(LISTA *l)
{
  int i;
  for (i = 0; i < MAX - 1; i++)
    l->A[i].prox = i + 1;
  l->A[MAX - 1].prox = INVALIDO;
  l->inicio = INVALIDO;
  l->dispo = 0;
}