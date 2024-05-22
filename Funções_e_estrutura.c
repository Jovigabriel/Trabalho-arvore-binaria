#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct arvore {
  int info;
  struct arvore *esq;
  struct arvore *dir;
} arvore;

// Função para ler arquivo com a árvore
arvore *lerArvore(FILE *arq) {
  char c;
  int num;

  fscanf(arq, "%c", &c);
  fscanf(arq, "%d", &num);

  if (num == -1) {
    fscanf(arq, "%c", &c);
    return NULL;
  } else {
    arvore *a = (arvore *)malloc(sizeof(arvore));
    a->info = num;
    a->esq = lerArvore(arq);
    a->dir = lerArvore(arq);
    fscanf(arq, "%c", &c);
    return a;
  }
}

// Função para limpar a árvore da memória

void freearvore(arvore *a) {
  if (a != NULL) {
    freearvore(a->esq);
    freearvore(a->dir);
    free(a);
  }
}

// Função para imprimir em pre-ordem

void preOrdem(arvore *a) {
  if (a != NULL) {
    printf("%d ", a->info);
    preOrdem(a->esq);
    preOrdem(a->dir);
  }
}

// Função para imprimir em ordem

void emOrdem(arvore *a) {
  if (a != NULL) {
    preOrdem(a->esq);
    printf("%d ", a->info);
    preOrdem(a->dir);
  }
}

// Função para imprimir em pós-ordem

void posOrdem(arvore *a) {
  if (a != NULL) {
    preOrdem(a->esq);
    preOrdem(a->dir);
    printf("%d ", a->info);
  }
}

// Função para saber a altura de uma árvore

int altura(arvore *a) {

  if (a == NULL)
    return 0;
  else {
    int he = altura(a->esq);
    int hd = altura(a->dir);

    if (he > hd) {
      return he + 1;
    } else {
      return hd + 1;
    }
  }
}

// Função para imprimir elementos de um certo nível

void imprimirniveis(arvore *a, int cont, int n) {
  if (a != NULL) {

    if (cont == n) {
      printf("%d ", a->info);
    } else {
      imprimirniveis(a->esq, cont + 1, n);
      imprimirniveis(a->dir, cont + 1, n);
    }
  }
}

// Função para imprimir em largura

void largura(arvore *a, int h, int cont) {
  if (a != NULL) {

    imprimirniveis(a, 0, cont);

    if (cont < h) {
      largura(a, h, cont + 1);
    }
  }
}

// Função para verificar se um elemento existe na árvore

int existe(arvore *a, int x) {
  if (a == NULL) {
    return 0;
  } else if (a->info == x) {
    return 1;
  } else if (existe(a->esq, x) == 1) {
    return 1;
  }
  return existe(a->dir, x);
}

// Função que conta os elementos da árvore

int contarElementos(arvore *a) {
  if (a == NULL)
    return 0;
  else
    return 1 + contarElementos(a->esq) + contarElementos(a->dir);
}

// Função que imprime os nós folhas

void nofolha(arvore *a) {
  if (a != NULL) {

    if (a->esq == NULL && a->dir == NULL) {
      printf("%d ", a->info);
    }

    else {
      nofolha(a->esq);
      nofolha(a->dir);
    }
  }
}



// Função para saber se a arvore esta balanceada

int balanceado(arvore *a) {
  if (a == NULL)
    return 1;

  int he = altura(a->esq);
  int hd = altura(a->dir);
  if (abs(he - hd) <= 1 && balanceado(a->esq) && balanceado(a->dir))
    return 1;
  return 0;
}

// Função para saber se a arvore é cheia

int cheia(arvore *a) {
  if (a == NULL) {
    return 1;
  }
  if (a->dir == NULL && a->esq == NULL) {
    return 1;
  }
  if ((a->dir != NULL && a->esq == NULL) ||
      (a->dir == NULL && a->esq != NULL)) {
    return 0;
  }

  return cheia(a->dir) && cheia(a->esq);
}


// Função para saber o nível do no de um certo elemento

void nivelDoNo(arvore *a, int x, int cont) {
  if (a != NULL) {
    if (a->info == x) {
      printf("%d", cont);
    }

    else {
      nivelDoNo(a->esq, x, cont + 1);
      nivelDoNo(a->dir, x, cont + 1);
    }
  }
}
