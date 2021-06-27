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
boolean removerPos(PILHA *p, int chave);

int main()
{
  PILHA p;
  inicializarPilha(&p);
  REGISTRO r1, r2, r3, r4;

  r1.chave = 1;
  r2.chave = 10;
  r3.chave = 14;
  r4.chave = 11;
  push(&p, r1);
  push(&p, r2);
  push(&p, r3);
  push(&p, r4);

  exibir(&p);
  removerPos(&p, 14);
  exibir(&p);

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
    printf("%d ", p->A[i].chave);
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

boolean removerPos(PILHA *p, int chave)
{
  PILHA aux;
  inicializarPilha(&aux);

  while (tamanho(p) > 0 && p->A[p->topo].chave != chave)
  {
    push(&aux, p->A[p->topo]);
    pop(p);
  }

  if (tamanho(p) > 0)
  {
    pop(p);
  }

  while (tamanho(&aux) > 0)
  {
    push(p, aux.A[aux.topo]);
    pop(&aux);
  }

  return true;
}