#include <stdio.h>
#define MAX 50

typedef enum
{
  false = 0,
  true = 1
} boolean;

typedef int TIPOCHAVE;

typedef struct
{
  TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
  REGISTRO A[MAX];
  int nroElem;
} LISTA;

void inicializarLista(LISTA *l);
int tamanho(LISTA *l);
void exibirLista(LISTA *l);
int buscaSequencial(LISTA *l, TIPOCHAVE ch);
boolean inserirElemLista(LISTA *l, REGISTRO reg, int i);
boolean excluirElemLista(LISTA *l, TIPOCHAVE ch);
void reinicializaLista(LISTA *l);
int buscaSentinela(LISTA *l, TIPOCHAVE ch);
boolean inserirElemListaOrd(LISTA *l, REGISTRO reg);
int buscaBinaria(LISTA *l, TIPOCHAVE ch);

int main()
{
  LISTA l;
  REGISTRO r1, r2, r3;

  inicializarLista(&l);

  r1.chave = 20;
  r2.chave = 21;
  r3.chave = 22;

  inserirElemLista(&l, r1, 0);
  inserirElemLista(&l, r2, 1);
  inserirElemLista(&l, r3, 0);

  printf("\n\n tamanho da lista: %d\n\n", tamanho(&l));
  exibirLista(&l);
  printf("\n %d", buscaSequencial(&l, 23));
  printf("\n %d", buscaSequencial(&l, 21));
  excluirElemLista(&l, 20);
  printf("\n\n tamanho da lista: %d\n\n", tamanho(&l));
  exibirLista(&l);

  return 0;
}

void inicializarLista(LISTA *l)
{
  l->nroElem = 0;
}

int tamanho(LISTA *l)
{
  return l->nroElem;
}

void exibirLista(LISTA *l)
{
  int i, fim = tamanho(l);
  printf(" Lista: \" ");
  for (i = 0; i < fim; i++)
    printf("%d%c", l->A[i].chave, (i < fim - 1) ? ',' : ' ');
  printf("\"\n");
}

int buscaSequencial(LISTA *l, TIPOCHAVE ch)
{
  int i = 0;

  while (i < l->nroElem)
  {
    if (ch == l->A[i].chave)
      return i;
    i++;
  }
  return -1;
}

boolean inserirElemLista(LISTA *l, REGISTRO reg, int i)
{
  int j;
  if ((l->nroElem == MAX) || (i < 0) || (i > l->nroElem))
    return false;
  for (j = l->nroElem; j > i; j--)
    l->A[j] = l->A[j - 1];
  l->A[j] = reg;
  l->nroElem++;
  return true;
}

boolean excluirElemLista(LISTA *l, TIPOCHAVE ch)
{
  int pos, j;
  if (pos = buscaSequencial(l, ch) == -1)
    return false;
  for (j = pos; j < l->nroElem - 1; j++)
    l->A[j] = l->A[j + 1];
  l->nroElem--;
  return true;
}

void reinicializaLista(LISTA *l)
{
  l->nroElem = 0;
}

int buscaSentinela(LISTA *l, TIPOCHAVE ch)
{
  int i = 0;
  l->A[l->nroElem].chave = ch;
  while (l->A[i].chave != ch)
    i++;
  if (i == l->nroElem)
    return -1;
  return i;
}

boolean inserirElemListaOrd(LISTA *l, REGISTRO reg)
{
  if (l->nroElem >= MAX)
    return false;
  int pos = l->nroElem;
  while (pos > 0 && l->A[pos - 1].chave > reg.chave)
  {
    l->A[pos] = l->A[pos - 1];
    pos--;
  }
  l->A[pos] = reg;
  l->nroElem++;
}

int buscaBinaria(LISTA *l, TIPOCHAVE ch)
{
  int esq = 1, dir = l->nroElem - 1, meio;
  while (esq <= dir)
  {
    meio = ((esq + dir) / 2);
    if (l->A[meio].chave == ch)
      return meio;
    else
    {
      if (l->A[meio].chave < ch)
        esq = meio + 1;
      else
        dir = meio - 1;
    }
  }
  return -1;
}