#include <stdio.h>
#include <stdlib.h>
#include "criaVet.h"
#include "invertVet.h"

int main(){

    /*Questão 1
    p++: Avança o ponteiro para o próximo indice.
    (*p)++: Soma 1 ao valor apontado.
    *(p++): Ele printa o valor atual e depois avança o ponteiro para o próximo indice. 
    *(p+10): Pula 10 indices e printa o valor.
    */

    //Questão 2
    int y, *p, x;
    y = 0;
    p = &y; //ponteiro p recebe o endereço de y
    x = *p; // x recebe o valor do ponteiro que é zero
    x = 4; // x recebe 4
    (*p)++;// soma 1 ao valor de y indo de 0 para 1
    x--; //diminui 1 no valor indo de 4 para 3
    (*p) += x; // soma o valor de p com o x, 1 + 3 = 4
    printf ("y = %d\n", y);


    //Questão 3
    int x, *p, **q;
    p = &x;
    q = &p;
    x = 10;
    printf("\n%d\n", **q);

    //Questão 4
    int *v, n;
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &n);
    cria_vet(v, n);

    //Questão 5
    int v1[5] = {1,2,3,4,5};
    int *v2;
    int n = 5;
    
    v2 = malloc( n * sizeof(int));
    
    if(v2 == NULL){
        printf("n alocou parça\n");
    }
    
    invert_vet(v1, v2, 5);




    free(v1);
    free(v2);
    return 0;
}
