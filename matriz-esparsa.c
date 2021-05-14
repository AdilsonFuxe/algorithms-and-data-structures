#include <stdio.h>
#include <malloc.h>

typedef struct aux
{
  float valor;
  int coluna;
  struct aux *prox;
} NO, *PONT;

typedef struct
{
  PONT *A;
  int linhas;
  int colunas;
} MATRIZ;

int main()
{

  return 0;
}