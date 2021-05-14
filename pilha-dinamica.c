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
void exibirPilha(PILHA *p);
boolean inserirElemPilha(PILHA *p, REGISTRO reg);
boolean excluirElemPilha(PILHA *p);
void reinicializarPilha(PILHA *p);

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

void exibirPilha(PILHA *p)
{
  PONT end = p->topo;
  printf("Pilha: \" ");
  while (end != NULL)
  {
    printf("%d ", end->reg.chave);
    end = end->prox;
  }
  printf("\"\n");
}

boolean inserirElemPilha(PILHA *p, REGISTRO reg)
{
  PONT novo = (PONT)malloc(sizeof(ELEMENTO));
  novo->reg = reg;
  novo->prox = p->topo;
  p->topo = novo;
  return true;
}

boolean excluirElemPilha(PILHA *p)
{
  if (p->topo == NULL)
    return false;
  PONT apagar = p->topo;
  p->topo = p->topo->prox;
  free(apagar);
}

void reinicializarPilha(PILHA *p)
{
  PONT end = p->topo;

  while (end != NULL)
  {
    PONT aux = end;
    end = end->prox;
    free(aux);
  }
  p->topo = NULL;
}