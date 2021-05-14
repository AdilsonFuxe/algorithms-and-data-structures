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

int main()
{
  return 0;
}