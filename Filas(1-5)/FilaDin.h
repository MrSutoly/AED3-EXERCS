#ifndef FILADIN_H
#define FILADIN_H

typedef struct No {
    int matricula;
    struct No *prox;
} No;

typedef struct {
    No *frente;
    No *tras;
} Fila;

typedef struct NoPilha {
    int dado;
    struct NoPilha *prox;
} NoPilha;

typedef struct {
    NoPilha *topo;
} Pilha;

typedef struct {
    Fila *dados[100];
    int frente, tras;
} FilaDeFilas;

typedef struct {
    Pilha *dados[100];
    int frente, tras;
} FilaDePilhas;

typedef struct {
    Fila *dados[100];
    NoPilha *topo;
} PilhaDeFilas;

typedef struct {
    int id;
    char nome[50];
    char destino[50];
} Aviao;

void inicializaFila(Fila *f);
int filaVazia(Fila *f);
void enfileira(Fila *f, int mat);
int desenfileira(Fila *f, int *mat);
void imprimeFila(Fila *f);

int separa(Fila *f1, Fila *f2, int n);

void inicializaFilaDeFilas(FilaDeFilas *ff);
void enfileiraFila(FilaDeFilas *ff, Fila *f);

void inicializaFilaDePilhas(FilaDePilhas *fp);
void enfileiraPilha(FilaDePilhas *fp, Pilha *p);

void inicializaPilhaDeFilas(PilhaDeFilas *pf);
void empilhaFila(PilhaDeFilas *pf, Fila *f);

void inverteFila(Fila *f);

typedef struct {
    int dados[100];
    int frente, tras, tam;
} FilaCircular;

void inicializaFilaCircular(FilaCircular *f);
int filaCircularVazia(FilaCircular *f);
int filaCircularCheia(FilaCircular *f);
void enfileiraCircular(FilaCircular *f, int x);
int desenfileiraCircular(FilaCircular *f, int *x);
void furaFila(FilaCircular *f, int x);
void imprimeFilaCircular(FilaCircular *f);

void listarAvioes(Fila *f);
void autorizarDecolagem(Fila *f);
void adicionarAviao(Fila *f, Aviao a);
void listarPrimeiroAviao(Fila *f);

#endif
