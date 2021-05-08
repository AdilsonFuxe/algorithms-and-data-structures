#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef enum
{
  false = 0,
  true = 1
} boolean;

typedef struct
{
  TIPOCHAVE chave;
} REGISTRO;

typedef struct aux
{
  REGISTRO reg;
  struct aux *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct
{
  PONT inicio;
} LISTA;

void inicializarLista(LISTA *l);

int main()
{

  LISTA l;

  inicializarLista(&l);

  return 0;
}

void inicializarLista(LISTA *l)
{
  l->inicio = NULL;
}