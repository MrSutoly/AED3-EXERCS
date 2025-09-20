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

/*
 * Combina duas filas ordenadas (f1 e f2) em uma terceira fila (f3),
 * mantendo a ordem crescente dos elementos.
 *
 * Retorna 1 se a operação for bem-sucedida, 0 caso contrário.
 */
int separaEFilaEmOrdem(Fila *f1, Fila *f2, Fila *f3) {
 // Verifica se as filas de entrada e a de saída são válidas
 if (f1 == NULL || f2 == NULL || f3 == NULL) {
return 0;
 }

// Se as duas filas de origem estiverem vazias, não há o que fazer
if (filaVazia(f1) && filaVazia(f2)) {
printf("Ambas as filas estao vazias\n");
return 0;
}

// Pega os primeiros nós de cada fila
 No *no1 = f1->frente;
No *no2 = f2->frente;

 // Percorre as duas filas, comparando e enfileirando o menor elemento na fila de destino
 while (no1 != NULL && no2 != NULL) {
 if (no1->matricula < no2->matricula) {
 enfileira(f3, no1->matricula);
 no1 = no1->prox;
} else {
 enfileira(f3, no2->matricula);
 no2 = no2->prox;
 }
 }

 // Adiciona os elementos restantes da primeira fila (se houver)
 while (no1 != NULL) {
enfileira(f3, no1->matricula);
 no1 = no1->prox;
 }

 // Adiciona os elementos restantes da segunda fila (se houver)
 while (no2 != NULL) {
 enfileira(f3, no2->matricula);
 no2 = no2->prox;
}
    return 1;
}


int Reverse(Fila *f) {
 if (f == NULL || filaVazia(f)) {
return 0; // Retorna 0 se a fila for nula ou vazia
 }

 // Declara ponteiros auxiliares para a inversão
 No *anterior = NULL;
No *atual = f->frente;
 No *proximo = NULL;

 // Inverte a direção dos ponteiros
 while (atual != NULL) {
 proximo = atual->prox; // Guarda o próximo nó
atual->prox = anterior; // Inverte o ponteiro do nó atual
anterior = atual; // Move o ponteiro 'anterior' para o nó atual
atual = proximo; // Move o ponteiro 'atual' para o próximo nó
 }

// O antigo 'frente' agora é o 'tras' e o antigo 'tras' é o 'frente'
f->tras = f->frente;
f->frente = anterior;

return 1;
}