
#ifndef CABECALHO_H
#define CABECALHO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Questão 4
void cria_vet(int *v, int n);

// Questão 5
void inverte_vet(int *v1, int *v2, int n);

// ----------------------------
// Questão 6
// ----------------------------
void imprimeStringInvertida(const char *s);

// ----------------------------
// Questão 7
// ----------------------------
struct Produto {
    int codigo;
    char nome[50];
    float preco;
};

void cad_prod(struct Produto *produto, int qtd);
void print_prod(struct Produto *produto, int qtd);
void busc_prod(struct Produto *produto, int qtd, int cod);

// ----------------------------
// Questão 8
// ----------------------------
void le_vet(int *v, int n);
void print_vet(int *v, int n);

// ----------------------------
// Questão 9
// ----------------------------
int **alocaMatriz(int m, int n);
void liberaMatriz(int **matriz, int m);

#endif //CABECALHO_H
