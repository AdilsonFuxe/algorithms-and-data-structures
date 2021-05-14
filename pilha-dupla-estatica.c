#include <stdio.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef enum
{
  false = 0,
  true = 1
} boolean;

typedef enum
{
  pilha1 = 0,
  pilha2 = 1
} TIPOPILHA;

typedef struct
{
  TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
  REGISTRO A[MAX];
  int topo1;
  int topo2;
} PILHADUPLA;

void inicializarPilhaDupla(PILHADUPLA *p);
int tamanhoPilhaDupla(PILHADUPLA *p);
void exibirPilha(PILHADUPLA *p, TIPOPILHA tipo);
boolean inserirElementoPilha(PILHADUPLA *p, REGISTRO reg, TIPOPILHA tipo);

int main()
{

  return 0;
}

void inicializarPilhaDupla(PILHADUPLA *p)
{
  p->topo1 = -1;
  p->topo2 = MAX;
}

int tamanhoPilhaDupla(PILHADUPLA *p)
{
  return (p->topo1 + 1) + (MAX - p->topo2);
}

void exibirPilha(PILHADUPLA *p, TIPOPILHA tipo)
{
  printf("PILHA: %d \" ", tipo);
  int i;

  if (tipo == pilha1)
    for (i = p->topo1; i >= 0; i--)
      printf("%d ", p->A[i].chave);
  else
    for (i = p->topo2; i < MAX; i++)
      printf("%d ", p->A[i].chave);
}

boolean inserirElementoPilha(PILHADUPLA *p, REGISTRO reg, TIPOPILHA tipo)
{
  if (p->topo1 + 1 == p->topo2)
    return false;

  if (tipo == pilha1)
  {
    p->topo1 = p->topo1 + 1;
    p->A[p->topo1] = reg;
  }
  else
  {
    p->topo2 = p->topo2 - 1;
    p->A[p->topo2] = reg;
  }
  return true;
}