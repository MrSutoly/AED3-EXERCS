#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

int main() {
    Fila f1, f2;
    inicializaFila(&f1);
    inicializaFila(&f2);

    enfileira(&f1, 1);
    enfileira(&f1, 2);
    enfileira(&f1, 3);
    enfileira(&f1, 4);
    enfileira(&f1, 5);

    printf("Fila original: ");
    imprimeFila(&f1);

    separa(&f1, &f2, 3);

    printf("Fila 1: ");
    imprimeFila(&f1);
    printf("Fila 2: ");
    imprimeFila(&f2);

    printf("Invertendo fila 1:\n");
    inverteFila(&f1);
    imprimeFila(&f1);

    FilaCircular fc;
    inicializaFilaCircular(&fc);
    enfileiraCircular(&fc, 10);
    enfileiraCircular(&fc, 20);
    enfileiraCircular(&fc, 30);
    furaFila(&fc, 99);
    printf("Fila circular: ");
    imprimeFilaCircular(&fc);

    Aviao a1 = {1, "Gol", "SP"};
    Aviao a2 = {2, "Latam", "RJ"};
    Aviao a3 = {3, "Azul", "BH"};

    adicionarAviao(&f1, a1);
    adicionarAviao(&f1, a2);
    adicionarAviao(&f1, a3);

    listarAvioes(&f1);
    listarPrimeiroAviao(&f1);
    autorizarDecolagem(&f1);
    listarAvioes(&f1);

    printf("\n--- Testando a funcao de combinacao de filas ---\n");
    Fila fA, fB, fC;
    inicializaFila(&fA);
    inicializaFila(&fB);
    inicializaFila(&fC);

    // Preenchendo fA e fB em ordem crescente
    enfileira(&fA, 10);
    enfileira(&fA, 30);
    enfileira(&fA, 50);

    enfileira(&fB, 20);
    enfileira(&fB, 40);
    enfileira(&fB, 60);

    printf("Fila A (ordenada): ");
    imprimeFila(&fA);
    printf("Fila B (ordenada): ");
    imprimeFila(&fB);

    // Chamando a nova funcao para combinar fA e fB em fC
    separaEFilaEmOrdem(&fA, &fB, &fC);

    printf("Fila C (combinada e ordenada): ");
    imprimeFila(&fC);

    printf("\n--- Testando a funcao Reverse ---\n");
    Fila f_teste;
    inicializaFila(&f_teste);
    enfileira(&f_teste, 100);
    enfileira(&f_teste, 200);
    enfileira(&f_teste, 300);
    enfileira(&f_teste, 400);
    
    printf("Fila antes do Reverse: ");
    imprimeFila(&f_teste);
    
    Reverse(&f_teste);
    
    printf("Fila depois do Reverse: ");
    imprimeFila(&f_teste);
    
    return 0;
}
