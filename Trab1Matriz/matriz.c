#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

No* criarNo() {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = 0;
    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->cima = NULL;
    novo->baixo = NULL;
    return novo;
}

Matriz* alocarMatriz(int linhas, int colunas) {
    Matriz *m = (Matriz*)malloc(sizeof(Matriz));
    m->linhas = linhas;
    m->colunas = colunas;
    m->inicio = NULL;

    if (linhas <= 0 || colunas <= 0)
        return m;

    No *linhaAnterior = NULL;
    No *linhaAtual = NULL;

    for (int i = 0; i < linhas; i++) {
        No *colunaAnterior = NULL;
        No *novo = NULL;

        for (int j = 0; j < colunas; j++) {
            novo = criarNo();

            if (i == 0 && j == 0) {
                m->inicio = novo;
            }

            if (colunaAnterior != NULL) {
                colunaAnterior->direita = novo;
                novo->esquerda = colunaAnterior;
            }

            if (linhaAnterior != NULL) {
                No *acima = linhaAnterior;
                for (int k = 0; k < j; k++) {
                    acima = acima->direita;
                }
                acima->baixo = novo;
                novo->cima = acima;
            }
            colunaAnterior = novo;
        }
        if (i == 0) {
            linhaAnterior = m->inicio;
        } else {
            linhaAnterior = linhaAnterior->baixo;
        }
    }
    return m;
}

void desalocarMatriz(Matriz *m) {
    if (m == NULL || m->inicio == NULL)
        return;

    No *linha = m->inicio;
    while (linha != NULL) {
        No *coluna = linha;
        No *proxLinha = linha->baixo;
        while (coluna != NULL) {
            No *temp = coluna;
            coluna = coluna->direita;
            free(temp);
        }
        linha = proxLinha;
    }
    free(m);
}

No* acessarPosicao(Matriz *m, int x, int y) {
    if (m == NULL || x < 0 || y < 0 || x >= m->linhas || y >= m->colunas)
        return NULL;

    No *atual = m->inicio;
    for (int i = 0; i < x; i++)
        atual = atual->baixo;
    for (int j = 0; j < y; j++)
        atual = atual->direita;

    return atual;
}

void inserirValor(Matriz *m, int x, int y, int valor) {
    No *n = acessarPosicao(m, x, y);
    if (n == NULL) {
        printf("Posição inválida!\n");
        return;
    }
    n->valor = valor;
}

No* buscarValor(Matriz *m, int valor) {
    if (m == NULL) return NULL;

    No *linha = m->inicio;

    while (linha != NULL) {
        No *coluna = linha;
        while (coluna != NULL) {
            if (coluna->valor == valor)
                return coluna;
            coluna = coluna->direita;
        }
        linha = linha->baixo;
    }
    return NULL;
}

void imprimirVizinhos(Matriz *m, int x, int y) {
    No *n = acessarPosicao(m, x, y);
    if (n == NULL) {
        printf("Posição inválida!\n");
        return;
    }

    printf("Vizinhos de (%d,%d):\n", x, y);
    printf("Cima: %d\n", n->cima ? n->cima->valor : -1);
    printf("Baixo: %d\n", n->baixo ? n->baixo->valor : -1);
    printf("Esquerda: %d\n", n->esquerda ? n->esquerda->valor : -1);
    printf("Direita: %d\n", n->direita ? n->direita->valor : -1);
}

void imprimirMatriz(Matriz *m) {
    if (m == NULL || m->inicio == NULL)
        return;

    No *linha = m->inicio;
    while (linha != NULL) {
        No *coluna = linha;
        while (coluna != NULL) {
            printf("%3d ", coluna->valor);
            coluna = coluna->direita;
        }
        printf("\n");
        linha = linha->baixo;
    }
}
