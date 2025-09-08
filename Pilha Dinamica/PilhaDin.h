// PilhaDin.h

#ifndef PILHADIN_H
#define PILHADIN_H

#include <stdio.h>

// ================= Pilha de alunos =================

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Pilha;  // Pilha de alunos

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int consulta_topo_Pilha(Pilha* pi, struct aluno *al);
int insere_Pilha(Pilha* pi, struct aluno al);
int remove_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int Pilha_cheia(Pilha* pi);
void imprime_Pilha(Pilha* pi);
Pilha* pilha_copia(Pilha* p);
int Estatisticas_Pilha(Pilha* pi, struct aluno* maior, struct aluno* menor, float* media_geral);
int comparar_Pilhas(Pilha* pi1, Pilha* pi2);
int contador_pares_impares_Pilha(Pilha* pi, int* pares, int* impares);
void desempilha_n(int n, Pilha* pi);
void pop2(Pilha* pi);
int push2(Pilha* pi, struct aluno al1, struct aluno al2);

// ================= Pilha de caracteres =================

typedef struct elemento_char {
    char dado;
    struct elemento_char* prox;
} ElemChar;

typedef ElemChar* PilhaChar;

PilhaChar* cria_PilhaChar();
void libera_PilhaChar(PilhaChar* pi);
int insere_PilhaChar(PilhaChar* pi, char c);
int remove_PilhaChar(PilhaChar* pi);
int PilhaChar_vazia(PilhaChar* pi);
int consulta_topo_PilhaChar(PilhaChar* pi, char* c);
PilhaChar* pilha_copiaChar(PilhaChar* p);
int verifica(char* str);

#endif
