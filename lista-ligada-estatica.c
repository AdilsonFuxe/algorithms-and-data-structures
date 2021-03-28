#include <stdio.h>
#define MAX 50
#define INVALIDO -1

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
  REGISTRO reg;
  int prox;
} ELEMENTO;

typedef struct
{
  ELEMENTO A[MAX];
  int inicio;
  int dispo;
} LISTA;

void inicializarLista(LISTA *l);
int tamanho(LISTA *l);
void exibirLista(LISTA *l);
int buscaSequencialOrd(LISTA *l, TIPOCHAVE ch);
int obterNo(LISTA *l);
boolean inserirElemListaOrd(LISTA *l, REGISTRO reg);
boolean excluirElemList(LISTA *l, TIPOCHAVE ch);
void devolverNo(LISTA *l, int i);
int main()
{

  return 0;
}

void inicializarLista(LISTA *l)
{
  int i;
  for (i = 0; i < MAX - 1; i++)
    l->A[i].prox = i + 1;
  l->A[MAX - 1].prox = INVALIDO;
  l->inicio = INVALIDO;
  l->dispo = 0;
}

int tamanho(LISTA *l)
{
  int i = l->inicio;
  int count = 0;

  while (i != INVALIDO)
  {
    count++;
    i = l->A[i].prox;
  }
  return count;
}

void exibirLista(LISTA *l)
{
  int i = l->inicio;

  printf("Lista: \" ");
  while (i != INVALIDO)
  {
    printf("%d ", l->A[i].reg.chave);
    i = l->A[i].prox;
  }
  printf("\"\n");
}

int buscaSequencialOrd(LISTA *l, TIPOCHAVE ch)
{
  int i = l->inicio;

  while (i != INVALIDO && l->A[i].reg.chave < ch)
    i = l->A[i].prox;
  if (i != INVALIDO && l->A[i].reg.chave == ch)
    return i;
  return INVALIDO;
}

int obterNo(LISTA *l)
{
  int resultado = l->dispo;

  if (resultado != INVALIDO)
    l->dispo = l->A[l->dispo].prox;
  return resultado;
}

boolean inserirElemListaOrd(LISTA *l, REGISTRO reg)
{
  if (l->dispo == INVALIDO)
    return false;

  int ant = INVALIDO;
  int i = l->inicio;
  TIPOCHAVE ch = reg.chave;
  while ((i != INVALIDO) && (l->A[i].reg.chave < ch))
  {
    ant = i;
    i = l->A[i].prox;
  }

  if (i != INVALIDO && l->A[i].reg.chave == ch)
    return false;

  i = obterNo(l);
  l->A[i].reg = reg;

  if (ant == INVALIDO)
  {
    l->A[i].prox = l->inicio;
    l->inicio = i;
  }
  else
  {
    l->A[i].prox = l->A[ant].prox;
    l->A[ant].prox = i;
  }

  return true;
}

void devolverNo(LISTA *l, int i)
{
  l->A[i].prox = l->dispo;
  l->dispo = i;
}

boolean excluirElemList(LISTA *l, TIPOCHAVE ch)
{
  int ant = INVALIDO;
  int i = l->inicio;
  while ((i != INVALIDO) && (l->A[i].reg.chave < ch))
  {
    ant = i;
    i = l->A[i].prox;
  }
  if (i == INVALIDO || l->A[i].reg.chave != ch)
    return false;
  if (ant == INVALIDO)
    l->inicio = l->A[l->inicio].prox;
  else
    l->A[ant].prox = l->A[i].prox;
  devolverNo(l, i);
  return true;
}