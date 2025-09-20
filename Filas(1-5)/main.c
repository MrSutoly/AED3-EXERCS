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

    return 0;
}
