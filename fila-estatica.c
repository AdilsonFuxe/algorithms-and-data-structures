#include <stdio.h>

#define MAX 50

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

typedef struct
{
  REGISTRO A[MAX];
  int inicio;
  int nroElem;
} FILA;

void inicializarFIla(FILA *f);
int tamanho(FILA *f);
void exibirFila(FILA *f);
boolean inserirElemntoFIla(FILA *f, REGISTRO reg);
boolean excluirElementoFila(FILA *f);
void reinicializarFila(FILA *f);

int main()
{

  return 0;
}

void inicializarFIla(FILA *f)
{
  f->inicio = 0;
  f->nroElem = 0;
}

int tamanho(FILA *f)
{
  return f->nroElem;
}

void exibirFila(FILA *f)
{
  printf("Fila \" ");
  int i = f->inicio;
  int temp;

  for (temp = 0; temp < f->nroElem; temp++)
  {
    printf("%d ", f->A[i].chave);
    i = (i + 1) % MAX;
  }
  printf("\"\n");
}

boolean inserirElemntoFIla(FILA *f, REGISTRO reg)
{
  if (f->nroElem >= MAX)
    return false;
  int pos = (f->inicio + f->nroElem) % MAX;
  f->A[pos] = reg;
  f->nroElem++;
  return true;
}

boolean excluirElementoFila(FILA *f)
{
  if (f->nroElem == 0)
    return false;
  f->inicio = (f->inicio + 1) % MAX;
  f->nroElem--;
  return true;
}

void reinicializarFila(FILA *f)
{
  f->inicio = 0;
  f->nroElem = 0;
}