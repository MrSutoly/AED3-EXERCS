#ifndef TRABALHO1AED3_MATRIZ_H
#define TRABALHO1AED3_MATRIZ_H

#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *direita;
    struct No *baixo;
    struct No *esquerda;
    struct No *cima;
} No;

typedef struct {
    int linhas;
    int colunas;
    No *inicio;
} Matriz;

No* criarNo();
Matriz* alocarMatriz(int linhas, int colunas);
void desalocarMatriz(Matriz *m);
No* acessarPosicao(Matriz *m, int x, int y);
void inserirValor(Matriz *m, int x, int y, int valor);
No* buscarValor(Matriz *m, int valor);
void imprimirVizinhos(Matriz *m, int x, int y);
void imprimirMatriz(Matriz *m);

#endif //TRABALHO1AED3_MATRIZ_H