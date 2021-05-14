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
  int topo;
} PILHA;

void inicializarPilha(PILHA *p);
int tamanho(PILHA *p);
void exibir(PILHA *p);
boolean push(PILHA *p, REGISTRO reg);
boolean pop(PILHA *p);
void reinicializarPilha(PILHA *p);

int main()
{

  return 0;
}

void inicializarPilha(PILHA *p)
{
  p->topo = -1;
}

int tamanho(PILHA *p)
{
  return p->topo + 1;
}

void exibir(PILHA *p)
{
  printf("Pilha: \" ");
  int i;
  for (i = p->topo; i >= 0; i--)
  {
    printf("%d ", p->A[i]);
  }
  printf("\"\n");
}

boolean push(PILHA *p, REGISTRO reg)
{
  if (p->topo >= MAX - 1)
    return false;
  p->topo = p->topo + 1;
  p->A[p->topo] = reg;
  return true;
}

boolean pop(PILHA *p)
{
  if (p->topo < 0)
    return false;
  p->topo = p->topo - 1;
  return true;
}

void reinicializarPilha(PILHA *p)
{
  p->topo = -1;
}