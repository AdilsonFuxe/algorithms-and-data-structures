#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef struct
{
  TIPOCHAVE chave;
} REGISTRO;

typedef struct aux
{
  REGISTRO reg;
  struct aux *ant;
  struct aux *prox;
} ELEMENTO, *PONT;

typedef struct
{
  PONT cabeca;
} DEQUE;

void inicializarDeque(DEQUE *d);
int tamanho(DEQUE *d);
int tamanho2(DEQUE *d);

int main()
{

  return 0;
}

void inicializarDeque(DEQUE *d)
{
  d->cabeca = (PONT)malloc(sizeof(ELEMENTO));
  d->cabeca->prox = d->cabeca;
  d->cabeca->ant = d->cabeca;
}

int tamanho(DEQUE *d)
{
  PONT end = d->cabeca->prox;
  int tam = 0;

  while (end != d->cabeca)
  {
    tam++;
    end = end->prox;
  }

  return tam;
}

int tamanho2(DEQUE *d)
{
  PONT end = d->cabeca->ant;
  int tam = 0;
  while (end != d->cabeca)
  {
    tam++;
    end = end->ant;
  }

  return tam;
}