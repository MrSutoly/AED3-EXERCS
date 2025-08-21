#include "Cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cria_vet(int *v1, int n) {
    if (n <= 0) {
        printf("Tamanho inválido do vetor.\n");
    } else {
        v1 = malloc(n * sizeof(int));
        if (v1 == NULL) {
            printf("Erro ao alocar memória.\n");
        } else {
            printf("Vetor criado com sucesso.\n");
        }
    }
}


void inverte_vet(int *v1, int *v2, int n) {
    int mv = v1[0];
    for (int i = 0; i < n; i++) {
        v2[i] = v1[n - i - 1]; // copia invertido
        if (v1[i] > mv) {
            mv = v1[i];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d \n", v2[i]);
    }
    printf("O maior valor e %d \n", mv);
}

// Questão 6
void imprimeStringInvertida(const char *s) {
    int tamanho = 0;
    while (s[tamanho] != '\0') tamanho++;
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
    printf("\n");
}

// Questão 7
void cad_prod(struct Produto *produto, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("Digite codigo, nome e preco do produto %d:\n", i+1);
        scanf("%d", &produto[i].codigo);
        scanf("%s", produto[i].nome);
        scanf("%f", &produto[i].preco);
    }
}

void print_prod(struct Produto *produto, int qtd) {
    printf("\nLista de produtos:\n");
    for (int i = 0; i < qtd; i++) {
        printf("Codigo: %d | Nome: %s | Preco: %.2f\n",
               produto[i].codigo, produto[i].nome, produto[i].preco);
    }
}

void busc_prod(struct Produto *produto, int qtd, int cod) {
    for (int i = 0; i < qtd; i++) {
        if (produto[i].codigo == cod) {
            printf("\nProduto encontrado!\n");
            printf("Nome: %s\nPreco: %.2f\n", produto[i].nome, produto[i].preco);
            return;
        }
    }
    printf("\nProduto nao encontrado!\n");
}

// Questão 8
void le_vet(int *v, int n) {
    if (n > 0) {
        scanf("%d", &v[0]);
        le_vet(&v[1], n - 1);
    }
}

void print_vet(int *v, int n) {
    if (n > 0) {
        printf("%d\n", v[0]);
        print_vet(&v[1], n - 1);
    }
}

// Questão 9
int **alocaMatriz(int m, int n) {
    int **matriz = (int**) malloc(m * sizeof(int*));
    if (matriz == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        matriz[i] = (int*) malloc(n * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memoria\n");
            exit(1);
        }
    }
    return matriz;
}

void liberaMatriz(int **matriz, int m) {
    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);
}