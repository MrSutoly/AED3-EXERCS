#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaDin.h"

void inicializaFila(Fila *f) {
    f->frente = f->tras = NULL;
}

int filaVazia(Fila *f) {
    return f->frente == NULL;
}

void enfileira(Fila *f, int mat) {
    No *novo = malloc(sizeof(No));
    novo->matricula = mat;
    novo->prox = NULL;
    if(filaVazia(f)) {
        f->frente = f->tras = novo;
    } else {
        f->tras->prox = novo;
        f->tras = novo;
    }
}

int desenfileira(Fila *f, int *mat) {
    if(filaVazia(f)) return 0;
    No *tmp = f->frente;
    *mat = tmp->matricula;
    f->frente = tmp->prox;
    if(f->frente == NULL) f->tras = NULL;
    free(tmp);
    return 1;
}

void imprimeFila(Fila *f) {
    No *aux = f->frente;
    while(aux) {
        printf("%d ", aux->matricula);
        aux = aux->prox;
    }
    printf("\n");
}

int separa(Fila *f1, Fila *f2, int n) {
    if(filaVazia(f1)) return 0;
    No *aux = f1->frente;
    while(aux && aux->matricula != n) {
        aux = aux->prox;
    }
    if(aux == NULL || aux->prox == NULL) return 0;
    f2->frente = aux->prox;
    f2->tras = f1->tras;
    aux->prox = NULL;
    f1->tras = aux;
    return 1;
}

void inicializaFilaDeFilas(FilaDeFilas *ff) {
    ff->frente = ff->tras = 0;
}
void enfileiraFila(FilaDeFilas *ff, Fila *f) {
    ff->dados[ff->tras++] = f;
}

void inicializaFilaDePilhas(FilaDePilhas *fp) {
    fp->frente = fp->tras = 0;
}
void enfileiraPilha(FilaDePilhas *fp, Pilha *p) {
    fp->dados[fp->tras++] = p;
}

void inicializaPilhaDeFilas(PilhaDeFilas *pf) {
    pf->topo = NULL;
}
void empilhaFila(PilhaDeFilas *pf, Fila *f) {
    NoPilha *novo = malloc(sizeof(NoPilha));
    novo->dado = (int)f;
    novo->prox = pf->topo;
    pf->topo = novo;
}

void inverteFila(Fila *f) {
    Pilha p;
    p.topo = NULL;
    int x;
    while(desenfileira(f, &x)) {
        NoPilha *novo = malloc(sizeof(NoPilha));
        novo->dado = x;
        novo->prox = p.topo;
        p.topo = novo;
    }
    while(p.topo) {
        NoPilha *aux = p.topo;
        enfileira(f, aux->dado);
        p.topo = aux->prox;
        free(aux);
    }
}

void inicializaFilaCircular(FilaCircular *f) {
    f->frente = f->tras = f->tam = 0;
}
int filaCircularVazia(FilaCircular *f) {
    return f->tam == 0;
}
int filaCircularCheia(FilaCircular *f) {
    return f->tam == 100;
}
void enfileiraCircular(FilaCircular *f, int x) {
    if(filaCircularCheia(f)) return;
    f->dados[f->tras] = x;
    f->tras = (f->tras + 1) % 100;
    f->tam++;
}
int desenfileiraCircular(FilaCircular *f, int *x) {
    if(filaCircularVazia(f)) return 0;
    *x = f->dados[f->frente];
    f->frente = (f->frente + 1) % 100;
    f->tam--;
    return 1;
}
void furaFila(FilaCircular *f, int x) {
    if(filaCircularCheia(f)) return;
    f->frente = (f->frente - 1 + 100) % 100;
    f->dados[f->frente] = x;
    f->tam++;
}
void imprimeFilaCircular(FilaCircular *f) {
    int i, idx = f->frente;
    for(i = 0; i < f->tam; i++) {
        printf("%d ", f->dados[idx]);
        idx = (idx + 1) % 100;
    }
    printf("\n");
}

void listarAvioes(Fila *f) {
    int cont = 0;
    No *aux = f->frente;
    while(aux) {
        cont++;
        aux = aux->prox;
    }
    printf("Avioes na fila: %d\n", cont);
}

void autorizarDecolagem(Fila *f) {
    int mat;
    if(desenfileira(f, &mat)) {
        printf("Aviao %d decolou\n", mat);
    } else {
        printf("Nenhum aviao na fila\n");
    }
}

void adicionarAviao(Fila *f, Aviao a) {
    enfileira(f, a.id);
    printf("Aviao %d (%s) para %s adicionado\n", a.id, a.nome, a.destino);
}

void listarPrimeiroAviao(Fila *f) {
    if(filaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    printf("Primeiro aviao tem id %d\n", f->frente->matricula);
}
