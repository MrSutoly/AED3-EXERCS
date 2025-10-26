#ifndef TRABALHO1_MATRIZ_H
#define TRABALHO1_MATRIZ_H

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
int addRow(Matriz *matriz, int linha);
int addColumn(Matriz *matriz, int coluna);
int removeRow(Matriz *matriz, int linha);
int removeColumn(Matriz *matriz, int coluna);
void transporMatriz(Matriz *m);
void rotacionar90GrausAntiHoraria(Matriz *m);
void rotacionar90GrausHoraria(Matriz *m);
int lerValor(Matriz *m, int linha, int coluna);
int matrizSimetrica(Matriz *m);

#endif //TRABALHO1_MATRIZ_H
