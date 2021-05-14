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
} ELEMENTO, *PONT;

typedef struct
{
  PONT inicio;
  PONT fim;
} FILA;

void inicializarFila(FILA *f);

int main()
{

  return 0;
}

void inicializarFila(FILA *f)
{
  f->inicio = NULL;
  f->fim = NULL;
}