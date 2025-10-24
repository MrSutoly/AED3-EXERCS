#include <stdio.h>
#include <stdlib.h>
#include "Arvores.h"

int main() {

    ArvBin *arvore = cria_ArvBin();

    insere_ArvBin(arvore, 1);
    insere_ArvBin(arvore, 4);
    insere_ArvBin(arvore, -5);
    insere_ArvBin(arvore, 3);
    insere_ArvBin(arvore, 7);


    printf("Tamanho: %d \n " , TotalNO_Arvore(arvore));


    libera_ArvBin(arvore);

    int N = 8, dados[8] = {50, 100, 30, 20, 40, 45, 35, 37};

    ArvBin* raiz = cria_ArvBin();

    for(int i = 0; i < N; i++)
        insere_ArvBin(raiz, dados[i]);

    printf("=== Pre-Ordem ===\n");
    preOrdem_ArvBin(raiz);

    printf("\n=== Em-Ordem ===\n");
    emOrdem_ArvBin(raiz);

    printf("\n=== Pos-Ordem ===\n");
    posOrdem_ArvBin(raiz);

    printf("\n=== Remocao do valor 50 ===\n");
    if(remove_ArvBin(raiz, 50)){
        printf("Removido com sucesso!\n");

        printf("\nPre-Ordem apos remocao:\n");
        preOrdem_ArvBin(raiz);

        printf("\nEm-Ordem apos remocao:\n");
        emOrdem_ArvBin(raiz);

        printf("\nPos-Ordem apos remocao:\n");
        posOrdem_ArvBin(raiz);
    } else {
        printf("Valor 50 NAO encontrado para remocao.\n");
    }

    int busca = 40;
    if(Cons_Arvore(raiz, busca))
        printf("\n Valor %d encontrado na arvore!\n", busca);
    else
        printf("\n Valor %d NAO esta na arvore.\n", busca);

    busca = 99;
    if(Cons_Arvore(raiz, busca))
        printf(" \n Valor %d encontrado na arvore!\n", busca);
    else
        printf(" \n Valor %d NAO esta na arvore.\n", busca);


    libera_ArvBin(raiz);
    printf("\nFim!\n");

    return 0;
}