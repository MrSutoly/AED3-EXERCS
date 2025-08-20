#include "criaVet.h"
#include <stdio.h>
#include <stdlib.h>

void cria_vet(int *v1, int n) {
    if(n <= 0){
        printf("Tamanho inválido do vetor.\n");
    }else{

    v1 = malloc(n * sizeof(int));
    
    if(v1 == NULL) {
        printf("Erro ao alocar memória.\n");
    }else{
        printf("Vetor criado com sucesso.\n");
    }
}
}