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
} ELEMENTO, *PONT;

typedef struct
{
  PONT inicio;
  PONT fim;
} FILA;

void inicializarFila(FILA *f);
int tamanho(FILA *f);
void exibirElemento(FILA *f);

int main()
{

  return 0;
}

void inicializarFila(FILA *f)
{
  f->inicio = NULL;
  f->fim = NULL;
}

int tamanho(FILA *f)
{
  PONT end = f->inicio;
  int tam = 0;
  while (end != NULL)
  {
    tam++;
    end = end->prox;
  }
  return tam;
}
void exibirElemento(FILA *f)
{
  PONT end = f->inicio;
  printf("Fila: \" ");
  while (end != NULL)
  {
    printf("%d ", end->reg.chave);
    end = end->prox;
  }
  printf("\"\n");
}