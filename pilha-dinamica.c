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
  PONT topo;
} PILHA;

void inicializarPilga(PILHA *p);
int tamanho(PILHA *p);
boolean estaVazia(PILHA *p);

int main()
{

  return 0;
}

void inicializarPilga(PILHA *p)
{
  p->topo = NULL;
}

int tamanho(PILHA *p)
{
  PONT end = p->topo;
  int tam = 0;
  while (end != NULL)
  {
    tam++;
    end = end->prox;
  }
  return tam;
}

boolean estaVazia(PILHA *p)
{
  return p->topo == NULL;
}