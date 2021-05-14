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
void exibirDequeInicio(DEQUE *d);
void exibirDequeFim(DEQUE *d);
boolean inserirFim(DEQUE *d, REGISTRO reg);
boolean excluirElemDequeInicio(DEQUE *d);

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

void exibirDequeInicio(DEQUE *d)
{
  PONT end = d->cabeca->prox;
  printf("Deque partindo do inicio: \" ");
  while (end != d->cabeca)
  {
    printf("%d ", end->reg.chave);
    end = end->prox;
  }
  printf("\"\n");
}

void exibirDequeFim(DEQUE *d)
{
  PONT end = d->cabeca->ant;
  printf("Deque partindo do fim: \" ");
  while (end != d->cabeca)
  {
    printf("%d ", end->reg.chave);
    end = end->ant;
  }
  printf("\"\n");
}

boolean inserirFim(DEQUE *d, REGISTRO reg)
{
  PONT novo = (PONT)malloc(sizeof(ELEMENTO));
  if (!novo)
    return false;
  novo->reg = reg;
  novo->prox = d->cabeca;
  novo->ant = d->cabeca->ant;
  d->cabeca->ant = novo;
  novo->ant->prox = novo;
  return true;
}

boolean excluirElemDequeInicio(DEQUE *d)
{
  if (d->cabeca->prox == d->cabeca)
    return false;
  PONT apagar = d->cabeca->prox;
  d->cabeca->prox = apagar->prox;
  apagar->prox->ant = d->cabeca;
  free(apagar);
  return true;
}