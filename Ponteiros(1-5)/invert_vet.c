#include <stdio.h>
#include <stdlib.h>
#include "invertVet.h"

void inverte_vet(int *v1, int *v2, int n) {
    int mv = v1[0];
        for(int i = 0; i < n; i++){
            v2[i] = v1[n - i - 1];
            if(v1[i] > mv){
                mv = v1[i];
            }
        }
        for(int i = 0; i < n; i++){
            printf("%d \n", v2[i]);
        }
        printf("o maior valor é de %d \n", mv);
}