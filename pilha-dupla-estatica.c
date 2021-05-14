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
  int topo1;
  int topo2;
} PILHADUPLA;

void inicializarPilhaDupla(PILHADUPLA *p);
int tamanhoPilhaDupla(PILHADUPLA *p);

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