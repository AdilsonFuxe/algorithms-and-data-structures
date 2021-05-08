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
int tamanho(LISTA *l);
void exibirLista(LISTA *l);
PONT buscaSequencial(LISTA *l, TIPOCHAVE ch);

int main()
{

  LISTA l;

  inicializarLista(&l);
  printf("Tamanho: %d\n", tamanho(&l));

  return 0;
}

void inicializarLista(LISTA *l)
{
  l->inicio = NULL;
}

int tamanho(LISTA *l)
{
  PONT end = l->inicio;
  int tam = 0;
  while (end != NULL)
  {
    tam++;
    end = end->prox;
  }
  return tam;
}

void exibirLista(LISTA *l)
{
  PONT end = l->inicio;

  printf("Lista: \" ");
  while (end != NULL)
  {
    printf("%d ", end->reg.chave);
    end = end->prox;
  }
  printf("\"\n");
}

PONT buscaSequencial(LISTA *l, TIPOCHAVE ch)
{
  PONT pos = l->inicio;

  while (pos != NULL)
  {
    if (pos->reg.chave != ch)
      return pos;
    pos = pos->prox;
  }
  return NULL;
}