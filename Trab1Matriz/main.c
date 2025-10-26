#include "matriz.h"
#include <stdio.h>

int main() {
    int linhas, colunas;
    printf("Digite o número de linhas e colunas da matriz: ");
    scanf("%d %d", &linhas, &colunas);

    Matriz *m = alocarMatriz(linhas, colunas);
    printf("Matriz encadeada criada com sucesso!\n");

    inserirValor(m, 0, 0, 10);
    inserirValor(m, 0, 1, 20);
    inserirValor(m, 1, 0, 30);
    inserirValor(m, 1, 1, 40);

    printf("\nMatriz atual:\n");
    imprimirMatriz(m);

    printf("\nConsultando valor na posicao (x,y):\n");
    No *n = acessarPosicao(m, 0, 3);
    n ? printf("Valor: %d\n", n->valor) : printf("Essa posicao (x,y) nao existe\n");

    printf("\nBuscando valor:\n");
    No *busca = buscarValor(m, 30);
    busca ? printf("Valor encontrado: %d\n\n", busca->valor) : printf("Valor não encontrado!\n");

    imprimirVizinhos(m, 1, 1);

    desalocarMatriz(m);
    printf("\nMatriz desalocada com sucesso!\n");

    return 0;
}
