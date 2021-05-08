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
PONT buscaSeqOrd(LISTA *l, TIPOCHAVE ch);
PONT buscaSequencialExc(LISTA *l, TIPOCHAVE ch, PONT *ant);
boolean inserirElemListaOrd(LISTA *l, REGISTRO reg);
boolean excluirElemLista(LISTA *l, TIPOCHAVE ch);
void reinicialiizarLLista(LISTA *l);

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

PONT buscaSeqOrd(LISTA *l, TIPOCHAVE ch)
{
  PONT pos = l->inicio;

  while (pos != NULL && pos->reg.chave < ch)
    pos = pos->prox;
  if (pos != NULL && pos->reg.chave == ch)
    return pos;
  return NULL;
}

PONT buscaSequencialExc(LISTA *l, TIPOCHAVE ch, PONT *ant)
{
  *ant = NULL;
  PONT atual = l->inicio;
  while ((atual != NULL) && (atual->reg.chave < ch))
  {
    *ant = atual;
    atual = atual->prox;
  }

  if ((atual != NULL) && (atual->reg.chave == ch))
    return atual;
  return NULL;
}

boolean inserirElemListaOrd(LISTA *l, REGISTRO reg)
{
  PONT ant, i;
  i = buscaSequencialExc(l, reg.chave, &ant);
  if (i != NULL)
    return false;
  i = (PONT)malloc(sizeof(ELEMENTO));
  i->reg = reg;
  if (ant == NULL)
  {
    i->prox = l->inicio;
    l->inicio = i;
  }
  else
  {
    i->prox = ant->prox;
    ant->prox = i;
  }
  return true;
}

boolean excluirElemLista(LISTA *l, TIPOCHAVE ch)
{
  PONT ant, i;
  i = buscaSequencialExc(l, ch, &ant);
  if (i == NULL)
    return false;
  if (ant == NULL)
    l->inicio = i->prox;
  else
    ant->prox = i->prox;
  free(i);
  return true;
}

void reinicialiizarLLista(LISTA *l)
{
  PONT end = l->inicio;
  while (end != NULL)
  {
    PONT apagar = end;
    end = end->prox;
    free(apagar);
  }
  l->inicio = NULL;
}