#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;

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

int main()
{

  return 0;
}