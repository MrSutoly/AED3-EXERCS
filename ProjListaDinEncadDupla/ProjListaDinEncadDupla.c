#include <stdio.h>
#include <stdlib.h>
#include "ProjListaDinEncadDupla.h"


List* createList() {

    List* list = malloc(sizeof(List));
    if (list != NULL) {
        *list = NULL;
    }
    return list;

}

void free_List(List* list) {

    if (list != NULL) {
        while (*list != NULL) {
            Element *element = *list;
            *list = (*list)->next;
            free(element);
        }
        free(list);
    }

}

int consult__by_position_List(List* list, int position, Student* student) {

    if (list == NULL || *list == NULL || position <= 0) {
        return 0;
    }

    Element *element = *list;
    int i = 1;
    while (element != NULL && i < position) {
        element = element->next;
        i++;
    }

    if (element == NULL) {
        return 0;
    }

    *student = element->data;
    return 1;

}

int consult_by_id_List(List* list, int id, Student* student) {

    if (list == NULL || *list == NULL) {
        return 0;
    }

    Element *element = *list;

    while (element != NULL && element->data.id != id) {
        element = element->next;
    }

    if (element == NULL) {
        return 0;
    }

    *student = element->data;
    return 1;

}

int insert_end_List(List* list, Student student) {

    if (list == NULL) {
        return 0;
    }

    Element *element = malloc(sizeof(Element));
    if (element == NULL) {
        return 0;
    }

    element->data = student;
    element->next = NULL;

    if (*list == NULL) {
        element->previous = NULL;
        *list = element;
        return 1;
    }

    Element *aux = *list;
    while (aux->next != NULL) {
        aux = aux->next;
    }

    aux->next = element;
    element->previous = aux;

    return 1;

}

int insert_begin_List(List* list, Student student) {

    if (list == NULL) {
        return 0;
    }

    Element *element = malloc(sizeof(Element));
    if (element == NULL) {
        return 0;
    }

    element->data = student;
    element->previous = NULL;
    element->next = *list;

    if (*list != NULL) {
        (*list)->previous = element;
    }

    *list = element;

    return 1;

}

int remove_end_List(List* list) {

    if (list == NULL || *list == NULL) {
        return 0;
    }

    Element *element = *list;

    while (element->next != NULL) {
        element = element->next;
    }

    if (element->previous == NULL) {
        *list = element->next;
    } else {
        element->previous->next = NULL;
    }

    free(element);
    return 1;

}

int remove_begin_List(List* list) {

    if (list == NULL || *list == NULL) {
        return 0;
    }

    Element *element = *list;
    *list = element->next;

    if (element->next == NULL) {
        element->next->previous = NULL;
    }

    free(element);
    return 1;

}

int size__List(List* list) {

    if (list == NULL || *list == NULL) {
        return 0;
    }

    int cont = 0;

    Element *element = *list;

    while (element != NULL) {
        cont += 1;
        element = element->next;
    }

    return cont;

}

int full_list(List* list) {

    return 0;

}

int empty_List(List* list) {

    if (list == NULL || *list == NULL) {
        return 1;
    }

    return 0;

}

void print_List(List* list) {

    if (list != NULL) {
        Element *element = *list;

        while (element != NULL) {
            printf("-------------------------------\n\n");
            printf("ID: %d\n", element->data.id);
            printf("Name: %s\n", element->data.name);
            printf("Grades: %.1f, %.1f, %.1f\n", element->data.g1, element->data.g2, element->data.g3);
            printf("-------------------------------\n\n");

            element = element->next;
        }
    }

}

int remove_by_id_List(List* list, int id) {

    if (list == NULL || *list == NULL) {
        return 0;
    }

    Element *element = *list;

    while (element != NULL && element->data.id != id) {
        element = element->next;
    }

    if (element == NULL) {
        return 0;
    }

    if (element == *list) {
        *list = (*list)->next;
        if (*list != NULL) {
            (*list)->previous = NULL;
        }
        free(element);
        return 1;
    }

    if (element->next == NULL) {
        element->previous->next = NULL;
        free(element);
        return 1;
    }

    element->previous->next = element->next;
    element->next->previous = element->previous;
    free(element);

    return 1;

}

int Insert_Order_List(List* list, Student data) {

    if (list == NULL) {
        return 0;
    }

    Element *element = malloc(sizeof(Element));
    if (element == NULL) {
        return 0;
    }

    element->data = data;

    if (*list == NULL) {
        element->next = NULL;
        element->previous = NULL;
        *list = element;
        return 1;
    }

    Element* before = NULL;
    Element* current = *list;

    while (current != NULL && current->data.id < data.id) {
        before = current;
        current = current->next;
    }

    if (current == *list) {
        element->next = *list;
        element->previous = NULL;
        (*list)->previous = element;
        *list = element;
        return 1;
    }

    if (before != NULL) {
        element->next = current;
        if (current != NULL) {
            current->previous = element;
        }
        element->previous = before;
        before->next = element;
        return 1;
    }

    return 0;
}

int count_grade_List(List* list, float grade1) {

    if (list == NULL || *list == NULL) {
        return 0;
    }


    int cont = 0;
    while ((*list)->next != NULL) {
        if ((*list)->data.g1 == grade1) {
            cont += 1;
        }
        *list = (*list)->next;
    }

    if ((*list)->data.g1 == grade1) {
        cont += 1;
    }

    while ((*list)->previous != NULL) {
        *list = (*list)->previous;
    }

    return cont;
}
/*
 * Tive que adicionar mais um if fora do while, porque a contagem sai do loop antes de verificar para o ultimo elemento,
 * afinal, se avançasse o *list até o final, não teria como voltar pois ele estaria travado no NULL
 */

 
int insert_begin_List_Circ(List* list, Student student) {
    Element* newNode = (Element*) malloc(sizeof(Element));
    if (newNode == NULL) {
        return 0; 
    }
    newNode->data = student;

    if (*list == NULL) {
        *list = newNode;
        newNode->next = newNode;
        newNode->previous = newNode;
    } else {
        Element* head = *list;
        Element* last = head->previous; 

       
        newNode->next = head;
        newNode->previous = last;

        
        last->next = newNode;
        head->previous = newNode;
        *list = newNode;
    }
    return 1; 
}


int insert_end_List_Circ(List* list, Student student) {

    Element* newNode = (Element*) malloc(sizeof(Element));
    if (newNode == NULL) {
        return 0; // Falha
    }
    newNode->data = student;

    if (*list == NULL) {
        *list = newNode;
        newNode->next = newNode;
        newNode->previous = newNode;
    } else {
        Element* head = *list;
        Element* last = head->previous; 

        newNode->next = head;
        newNode->previous = last;

        last->next = newNode;
        head->previous = newNode;
    }
    return 1; 
}

int remove_begin_List_Circ(List* list) {
    if (*list == NULL) {
        return 0;
    }

    Element* nodeToRemove = *list;

    if (nodeToRemove->next == nodeToRemove) {
        *list = NULL; 
    } else {
        Element* newHead = nodeToRemove->next;
        Element* last = nodeToRemove->previous;

        last->next = newHead;
        newHead->previous = last;

        *list = newHead;
    }

    free(nodeToRemove); 
    return 1; 
}


int remove_end_List_Circ(List* list) {
    if (*list == NULL) {
        return 0;
    }

    Element* head = *list;
    Element* nodeToRemove = head->previous; 

    if (nodeToRemove == head) { 
        *list = NULL;
    } else {

        Element* newLast = nodeToRemove->previous; 

        newLast->next = head;
        head->previous = newLast;
    }

    free(nodeToRemove); 
    return 1; 
}

void print_circular_List(List* list) {
    if (list == NULL || *list == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    Element* aux = *list; 

    printf("Print Lista Circular\n");
    do {
        printf("ID: %d, Nome: %s\n", aux->data.id, aux->data.name);
        aux = aux->next;
    } while (aux != *list); 
}

//5

int enfileirar(noDesc *n, int elem) {
    Fila* novo = (Fila*) malloc(sizeof(Fila));
    if (novo == NULL) {
        return 0;
    }

    novo->info = elem;
    novo->prox = NULL; 

    if (n->ini == NULL) {
        n->ini = novo;
        n->fim = novo;
        novo->ant = NULL; 
    } else {
        novo->ant = n->fim;   
        n->fim->prox = novo;  
        n->fim = novo;        
    }

    return 1; 
}

int desenfileirar(noDesc *n, int *elem) {
    if (n->ini == NULL) {
        return 0; 
    }

    Fila* noRemover = n->ini;

    *elem = noRemover->info;

    n->ini = noRemover->prox;

    if (n->ini == NULL) {
        n->fim = NULL;
    } else {
        n->ini->ant = NULL;
    }
    free(noRemover);

    return 1; 
}