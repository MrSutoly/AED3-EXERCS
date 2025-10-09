#include <stdio.h>
#include "ProjListaDinEncadDupla.h"

int main() {

    Student a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    List* li = createList();

    printf("Tamanho: %d\n",size__List(li));
    print_List(li);

    int i;
    for(i=0; i < 4; i++) {
        insert_end_List(li,a[i]);
    }

    printf("\n\n\n\n Tamanho: %d\n",size__List(li));
    print_List(li);

    remove_by_id_List(li, 1);
    printf("\n\n\n\n Tamanho: %d\n",size__List(li));
    print_List(li);

    remove_by_id_List(li,3);
    printf("\n\n\n\n Tamanho: %d\n",size__List(li));
    print_List(li);

    for(int i = 0; i < 4; i++) {
        Insert_Order_List(li,a[i]);
    }

    printf("\n\n\n\n Tamanho: %d\n",size__List(li));
    print_List(li);

    for(int i = 0; i < 4; i++) {
        insert_end_List(li,a[i]);
    }

    printf("\n\n\n\n Tamanho: %d\n",size__List(li));
    print_List(li);

    printf("Quantidade de estudantes que tiveram 9.5 como nota 1: %d", count_grade_List(li, 9.5));

    free_List(li);

    List list = NULL;

    insert_end_List_Circ(&list, a[2]);
    insert_end_List_Circ(&list, a[3]);
    insert_begin_List_Circ(&list, a[1]);

    print_circular_List(&list);

    remove_begin_List_Circ(&list);
    print_circular_List(&list);

    remove_end_List_Circ(&list);
    print_circular_List(&list);

    noDesc fila;
    fila.ini = NULL;
    fila.fim = NULL;

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);
    print_List(&list);

    int removido;
    desenfileirar(&fila, &removido);
    printf("Removido: %d\n", removido);
    print_List(&list);
    return 0;
}