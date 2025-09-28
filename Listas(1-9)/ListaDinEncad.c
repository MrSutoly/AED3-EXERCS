#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

#include <string.h>

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elemento* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){
        *li = no;
    }else{
        Elemento *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento* no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere in�cio
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elemento *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere in�cio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elemento *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//n�o encontrado
        return 0;

    if(no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elemento* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elemento* no = *li;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

void al_mat(Lista* li, int mat) {
    if(li == NULL) printf("Ta vazia a lista dog");
    Elemento* aux = *li;
    while(aux != NULL) {
        if(aux->dados.matricula == mat) {
            printf("O aluno de nome: %s e de matricula %d foi encontrado! \n", aux->dados.nome, aux->dados.matricula);
            return;
        }
        aux = aux->prox;
    }
    printf("Aluno com matricula %d nao encontrado!\n", mat);
}

void al_pos(Lista* li, int pos) {
    if(li == NULL) printf("Ta vazia a lista dog");
    int i = 0;
    Elemento* aux = *li;
    pos = pos - 1;
    while (i < pos) {
        aux = aux->prox;
        i++;
    }
    printf("o aluno na posicao %d e %s \n", pos, aux->dados.nome);
}

int al_rec_val(Lista* li, int info) {
    if(li == NULL) printf("Ta vazia a lista dog");

    if ((*li)->dados.matricula == info) {
        Elemento* temp = *li;
        *li = (*li)->prox;
        free(temp);
        return 1;
    }

    return al_rec_val(&((*li)->prox), info);
}

int al_rec_eq(Lista* li1, Lista* li2) {
    if (li1 == NULL && li2 == NULL) return 1;

    if(li1 == NULL || li2 == NULL) return 0;

    if ((*li1)->dados.matricula != (*li2)->dados.matricula) return 0;

    if (strcmp((*li1)->dados.nome, (*li2)->dados.nome) != 0) return 0;

    if ((*li1)->dados.n1 != (*li2)->dados.n1 || (*li1)->dados.n2 != (*li2)->dados.n2 || (*li1)->dados.n3 != (*li2)->dados.n3) return 0;

    return al_rec_eq(&((*li1)->prox), &((*li2)->prox));
}

void put_pos(Lista* li, int pos, struct aluno al) {
    if(li == NULL) {
        printf("Lista nao existe!\n");
        return;
    }
    if(pos < 0) {
        printf("Posicao invalida!\n");
        return;
    }

    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    if(novo == NULL) {
        printf("Erro de alocacao\n");
        return;
    }
    novo->dados = al;
    novo->prox = NULL;

    if(pos == 0 || *li == NULL) {
        novo->prox = *li;
        *li = novo;
        return;
    }

    Elemento* atual = *li;
    Elemento* ant = NULL;
    int i = 0;

    while(i < pos && atual != NULL) {
        ant = atual;
        atual = atual->prox;
        i++;
    }

    ant->prox = novo;
    novo->prox = atual;
}

typedef struct no {
    float valor;
    struct no* prox;
} No;

typedef No* List;

void put_vet_lista(float v[], int n) {
    List li = NULL;
    No* ultimo = NULL;

    for ( int i = 0; i < n; i++ ) {
        No* novo = (No*)malloc(sizeof(No));
        if (novo == NULL) return;

        novo->valor = v[i];
        novo->prox = NULL;

        if (li == NULL) li = novo;
        else {
            ultimo->prox = novo;
        }
        ultimo = novo;
    }
}

typedef struct nozin {
    int dado;
    struct nozin* prox;
} noz;

typedef noz* Listt;

void dell_num_list(Listt* li, int n) {
    if (li == NULL) return;

    Listt aux = *li;

    if ((*li)->dado == n) {
        *li = (*li)->prox;
        free(aux);
        dell_num_list(li, n);
    }else {
        dell_num_list(&(*li)->prox, n);
    }
}