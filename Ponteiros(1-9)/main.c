#include <stdio.h>
#include <stdlib.h>
#include "Cabecalho.h"


int main() {
    /*Questão 1
    p++: Avança o ponteiro para o próximo indice.
    (*p)++: Soma 1 ao valor apontado.
    *(p++): Ele printa o valor atual e depois avança o ponteiro para o próximo indice.
    *(p+10): Pula 10 indices e printa o valor.
    */

    // Questão 2
    {
        int y, *p, x;
        y = 0;
        p = &y; //ponteiro p recebe o endereço de y
        x = *p; // x recebe o valor do ponteiro que é zero
        x = 4; // x recebe 4
        (*p)++;// soma 1 ao valor de y indo de 0 para 1
        x--; //diminui 1 no valor indo de 4 para 3
        (*p) += x; // soma o valor de p com o x, 1 + 3 = 4
        printf("\nQuestao 2 -> y = %d\n", y);
    }

    // Questão 3
    {
        int x, *p, **q;
        p = &x;
        q = &p;
        x = 10;
        printf("\nQuestao 3 -> %d\n", **q);
    }

    // Questão 4
    {
        int *v = NULL, n;
        printf("\nQuestao 4 -> Digite o tamanho do vetor: ");
        scanf("%d", &n);
        cria_vet(v, n);
        free(v);
    }

    // Questão 5
    {
        int v1[5] = {1, 2, 3, 4, 5};
        int *v2;
        int n = 5;
        v2 = malloc(n * sizeof(int));
        if (v2 == NULL) {
            printf("Nao alocou memoria\n");
        } else {
            inverte_vet(v1, v2, n);
            free(v2);
        }
    }

    // Questão 6
    /*Declaro a variável,código pré-posto pelo professor,
                          abro um loop para contar o número de caracteres e armazeno
                          o resultado em tamanho, printo a string, invertendo as posições
                          (mesmo molde do exercício passado)
*/
    {
        char s[10] = "abcde";
        printf("\nQuestao 6 -> String invertida: ");
        imprimeStringInvertida(s);
    }

    // Questão 7
    /* Criei uma função para cadastrar usando for e preenchendo, dps outra
     * para printar a lista de produtos com uma condicional e por fim outra
     * para buscar pelo código comparando o código e depois printando se = */
    {
        int qtd = 3;
        struct Produto *produto = malloc(qtd * sizeof(struct Produto));
        if (produto == NULL) {
            printf("Erro ao alocar produtos!\n");
            return 1;
        }
        cad_prod(produto, qtd);
        print_prod(produto, qtd);

        int codigo;
        printf("\nDigite o codigo do produto que deseja buscar: ");
        scanf("%d", &codigo);
        busc_prod(produto, qtd, codigo);

        free(produto);
    }

    // Questão 8
    /* criei uma função que preenche e imprime o vetor, usei uma variável que caso
     * volte 0 faz ele preencher e caso volte 1 ele printa */
    {
        int *va, na;
        printf("\nQuestao 8 -> Digite o tamanho do vetor: ");
        scanf("%d", &na);
        va = malloc(na * sizeof(int));
        if (va == NULL) {
            printf("Erro ao alocar vetor!\n");
            return 1;
        }

        printf("Digite %d valores:\n", na);
        le_vet(va, na);

        printf("Vetor preenchido:\n");
        print_vet(va, na);

        free(va);
    }

    // Questão 9
    /*  Aloquei dinamicamente o espaço pras linhas e colunas e preenchi a matriz com uma função
     *  liberando o espaço dela com outra , trabalhosa mas a logica é simples. */
    {
        int m, n;
        printf("\nQuestao 9 -> Digite numero de linhas: ");
        scanf("%d", &m);
        printf("Digite numero de colunas: ");
        scanf("%d", &n);

        int **matriz = alocaMatriz(m, n);

        // Preenche a matriz com valores de exemplo
        for (int l = 0; l < m; l++) {
            for (int c = 0; c < n; c++) {
                matriz[l][c] = l + (2 * c);
            }
        }

        printf("\nMatriz %dx%d:\n", m, n);
        for (int l = 0; l < m; l++) {
            for (int c = 0; c < n; c++) {
                printf("%d ", matriz[l][c]);
            }
            printf("\n");
        }

        liberaMatriz(matriz, m);
    }

    return 0;
}
