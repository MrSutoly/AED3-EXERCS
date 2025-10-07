//
// Created by Pichau on 07/10/2025.
//

#ifndef PROJLISTADINENCADDUPLA_H
#define PROJLISTADINENCADDUPLA_H


typedef struct {

    int id;
    char name[30];
    float g1, g2, g3;

} Student;

typedef struct element {

    Student data;
    struct element *previous;
    struct element *next;

} Element;

typedef Element * List;

List* createList();
void free_List(List* list);
int consult__by_position_List(List* list, int position, Student* student);
int consult_by_id_List(List* list, int id, Student* student);
int insert_end_List(List* list, Student student);
int insert_begin_List(List* list, Student student);
int remove_end_List(List* list);
int remove_begin_List(List* list);
int size__List(List* list);
int full_list(List* list);
int empty_List(List* list);
void print_List(List* list);

int remove_by_id_List(List* list, int id);
int Insert_Order_List(List* list, Student data);
int count_grade_List(List* list, float grade1);

#endif //PROJLISTADINENCADDUPLA_H
