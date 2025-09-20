#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

// Protótipo e implementação da função menu
void menu() {
    printf("\n--- MENU DE OPCOES ---\n");
    printf("1 - Inicializar fila (dinamica).\n");
    printf("2 - Verificar se a fila eh vazia.\n");
    printf("3 - Verificar se a fila eh cheia (circular).\n");
    printf("4 - Enfileirar um elemento.\n");
    printf("5 - Desenfileirar um elemento.\n");
    printf("6 - Ler o primeiro elemento da fila.\n");
    printf("7 - Testar qual fila tem mais elementos.\n");
    printf("8 - Furar a fila (circular).\n");
    printf("9 - Sair.\n");
    printf("------------------------\n");
}

// Funcao de teste para a opcao 7
int testarFilaComMaisElementos(Fila *f1, Fila *f2) {
    // Simula a criacao de filas com tamanhos diferentes
    inicializaFila(f1);
    inicializaFila(f2);
    enfileira(f1, 1);
    enfileira(f1, 2);
    enfileira(f2, 1);
    enfileira(f2, 2);
    enfileira(f2, 3);
    
    printf("Fila 1 (2 elementos): ");
    imprimeFila(f1);
    printf("Fila 2 (3 elementos): ");
    imprimeFila(f2);
    
    printf("No momento, a Fila 2 possui mais elementos.\n");
    
    return 1;
}

int main() {
    // --- Testes sequenciais originais ---
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

    printf("\nInvertendo fila 1:\n");
    inverteFila(&f1);
    imprimeFila(&f1);

    FilaCircular fc_teste;
    inicializaFilaCircular(&fc_teste);
    enfileiraCircular(&fc_teste, 10);
    enfileiraCircular(&fc_teste, 20);
    enfileiraCircular(&fc_teste, 30);
    furaFila(&fc_teste, 99);
    printf("\nFila circular: ");
    imprimeFilaCircular(&fc_teste);

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

    // --- Inicio do menu interativo ---
    
    int opcao, matricula, retorno, valor_removido;
    Fila f_principal; // Fila principal para o menu
    FilaCircular fc_menu; // Fila circular para o menu

    inicializaFila(&f_principal);
    inicializaFilaCircular(&fc_menu);

    printf("\n\n--- INICIO DO MENU INTERATIVO ---\n");

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                inicializaFila(&f_principal);
                printf("Fila dinamica inicializada.\n");
                break;
            case 2: 
                if (filaVazia(&f_principal)) {
                    printf("A fila esta vazia.\n");
                } else {
                    printf("A fila nao esta vazia.\n");
                }
                break;
            case 3: 
                if (filaCircularCheia(&fc_menu)) {
                    printf("A fila circular esta cheia.\n");
                } else {
                    printf("A fila circular nao esta cheia.\n");
                }
                break;
            case 4: 
                printf("Digite a matricula para enfileirar: ");
                scanf("%d", &matricula);
                enfileira(&f_principal, matricula);
                printf("Elemento enfileirado. Fila atual: ");
                imprimeFila(&f_principal);
                break;
            case 5: 
                retorno = desenfileira(&f_principal, &valor_removido);
                if (retorno) {
                    printf("Elemento %d desenfileirado. Fila atual: ", valor_removido);
                    imprimeFila(&f_principal);
                } else {
                    printf("Nao foi possivel desenfileirar. A fila esta vazia.\n");
                }
                break;
            case 6: 
                listarPrimeiroAviao(&f_principal);
                break;
            case 7:
                Fila f_teste1, f_teste2;
                testarFilaComMaisElementos(&f_teste1, &f_teste2);
                break;
            case 8: 
                printf("Digite o valor para furar a fila circular: ");
                scanf("%d", &matricula);
                furaFila(&fc_menu, matricula);
                printf("Fila circular atual: ");
                imprimeFilaCircular(&fc_menu);
                break;
            case 9:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 9);
    
    return 0;
}
