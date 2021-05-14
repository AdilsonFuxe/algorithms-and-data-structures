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

typedef struct tempRegistro
{
  REGISTRO reg;
  struct tempRegistro *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct
{
  PONT cabeca;
} LISTA;

void inicializarLista(LISTA *l);
int tamanho(LISTA *l);

int main()
{
  return 0;
}

void inicializarLista(LISTA *l)
{
  l->cabeca = (PONT)malloc(sizeof(ELEMENTO));
  l->cabeca->prox = l->cabeca;
}

int tamanho(LISTA *l)
{
  PONT end = l->cabeca->prox;
  int tam = 0;
  while (end != l->cabeca)
  {
    tam++;
    end = end->prox;
  }
  return tam;
}