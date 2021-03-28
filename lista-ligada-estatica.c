#include <stdio.h>
#define MAX 50
#define INVALIDO -1

typedef int TIPOCHAVE;

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

int main()
{

  return 0;
}