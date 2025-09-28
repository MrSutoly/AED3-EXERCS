#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
int main(){
    struct aluno al, a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Lista* li = cria_lista();
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));

    int i;
    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);

    imprime_lista(li);
    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));

    for(i=0; i < 4; i++){
        remove_lista_final(li);
        imprime_lista(li);
        printf("\n Tamanho: %d\n\n\n",tamanho_lista(li));
    }

    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);
    imprime_lista(li);

    al_mat(li,3);

    al_pos(li, 3);


    // --- Teste de Concatenação ---
    printf("\n\n--- Testando a funcao de concatenacao ---\n\n");

    // Criando uma segunda lista
    Lista* li2 = cria_lista();

    // Elementos para a segunda lista
    struct aluno b[2] = {{5, "Felipe", 6.0, 7.0, 8.0},
                         {6, "Julia", 8.0, 8.5, 9.0}};

    // Inserindo elementos na segunda lista
    insere_lista_final(li2, b[0]);
    insere_lista_final(li2, b[1]);

    printf("Lista 1 antes da concatenacao:\n");
    imprime_lista(li);
    printf("Tamanho: %d\n", tamanho_lista(li));

    printf("\nLista 2 antes da concatenacao:\n");
    imprime_lista(li2);
    printf("Tamanho: %d\n", tamanho_lista(li2));

    printf("\nConcatenando Lista 2 na Lista 1...\n\n");

    // Chamando a funcao de concatenacao
    Concatenate_List(li, li2);

    printf("Lista 1 apos a concatenacao:\n");
    imprime_lista(li);
    printf("Tamanho: %d\n", tamanho_lista(li));

    printf("\nLista 2 apos a concatenacao (deve estar vazia):\n");
    imprime_lista(li2);
    printf("Tamanho: %d\n", tamanho_lista(li2));


    // --- TESTE DE REMOÇÃO DE DUPLICATAS ---
    printf("\n\n--- Testando a remocao de duplicatas ---\n\n");

    // Crie uma nova lista com elementos duplicados
    Lista* li_duplicada = cria_lista();
    struct aluno a_duplicados[7] = {{1, "Bianca", 9.7, 6.7, 8.4},
                                    {2, "Andre", 9.5, 7.8, 8.5},
                                    {1, "Bianca", 9.7, 6.7, 8.4}, // Duplicata
                                    {3, "Ana", 5.7, 6.1, 7.4},
                                    {2, "Andre", 9.5, 7.8, 8.5}, // Duplicata
                                    {4, "Ricardo", 7.5, 8.7, 6.8},
                                    {1, "Bianca", 9.7, 6.7, 8.4}}; // Outra duplicata

    // Insere os elementos, alguns deles repetidos
    for (i = 0; i < 7; i++) {
        insere_lista_final(li_duplicada, a_duplicados[i]);
    }

    printf("Lista com duplicatas:\n");
    imprime_lista(li_duplicada);

    // Chama a função para remover as duplicatas
    remove_duplicatas(li_duplicada);

    printf("\nLista apos a remocao de duplicatas:\n");
    imprime_lista(li_duplicada);


    // --- Teste de Fusão de Listas Ordenadas ---
    printf("\n\n--- Testando a fusao de listas ordenadas ---\n\n");

    // Crie duas novas listas ordenadas
    Lista* l1_fusao = cria_lista();
    Lista* l2_fusao = cria_lista();

    struct aluno fusao_a[3] = {{1, "Bianca", 9.7, 6.7, 8.4},
                               {3, "Ana", 5.7, 6.1, 7.4},
                               {5, "Carol", 8.0, 9.0, 8.5}};

    struct aluno fusao_b[3] = {{2, "Andre", 9.5, 7.8, 8.5},
                               {4, "Ricardo", 7.5, 8.7, 6.8},
                               {6, "Felipe", 7.0, 6.5, 7.5}};

    // Insere os elementos de forma ordenada
    for (i = 0; i < 3; i++) {
        insere_lista_final(l1_fusao, fusao_a[i]);
        insere_lista_final(l2_fusao, fusao_b[i]);
    }

    printf("Lista 1 antes da fusao:\n");
    imprime_lista(l1_fusao);

    printf("\nLista 2 antes da fusao:\n");
    imprime_lista(l2_fusao);

    printf("\nRealizando a fusao de Lista 2 em Lista 1...\n\n");

    // Chamando a funcao de fusao
    fusao_listas_ordenadas(l1_fusao, l2_fusao);

    printf("Lista 1 apos a fusao (deve estar ordenada com todos os elementos):\n");
    imprime_lista(l1_fusao);

    printf("\nLista 2 apos a fusao (deve estar vazia):\n");
    imprime_lista(l2_fusao);


    // --- NOVO TESTE DE TROCA DE ELEMENTOS ---
    printf("\n\n--- Testando a troca de elementos ---\n\n");

    // Lista de teste: 1 -> 2 -> 3 -> 4
    Lista* li_troca = cria_lista();
    struct aluno c[4] = {{1, "Bianca", 0, 0, 0},
                         {2, "Andre", 0, 0, 0},
                         {3, "Ana", 0, 0, 0},
                         {4, "Ricardo", 0, 0, 0}};

    for (i = 0; i < 4; i++) {
        insere_lista_final(li_troca, c[i]);
    }

    printf("Lista original:\n");
    imprime_lista(li_troca);

    // Trocar o primeiro com o segundo (1 com 2)
    printf("\nTroca do primeiro elemento (1) com o segundo...\n");
    struct elemento* p1 = busca_por_matricula(li_troca, 1);
    Troca(li_troca, p1);
    printf("Lista apos a troca:\n");
    imprime_lista(li_troca); // Deve ser 2 -> 1 -> 3 -> 4

    // Trocar o segundo com o terceiro (1 com 3)
    printf("\nTroca do elemento (1) com o elemento (3)...\n");
    struct elemento* p2 = busca_por_matricula(li_troca, 1);
    Troca(li_troca, p2);
    printf("Lista apos a troca:\n");
    imprime_lista(li_troca); // Deve ser 2 -> 3 -> 1 -> 4

    // Tentar trocar o ultimo elemento (4) com o proximo (nao existe)
    printf("\nTentando trocar o ultimo elemento (4)...\n");
    struct elemento* p3 = busca_por_matricula(li_troca, 4);
    if(Troca(li_troca, p3)) {
        printf("Troca realizada com sucesso!\n");
    } else {
        printf("Troca nao pode ser realizada (caso especial).\n");
    }
    printf("Lista permanece a mesma:\n");
    imprime_lista(li_troca);

    // Libera a memória das listas
    libera_lista(li);
    libera_lista(li_duplicada);
    libera_lista(l1_fusao);
    libera_lista(l2_fusao);
    libera_lista(li_troca);
    libera_lista(li2);
    
    system("pause");

    return 0;
}

