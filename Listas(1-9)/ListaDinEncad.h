#ifndef LISTADIN_H
#define LISTADIN_H


struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);
void al_mat(Lista* li, int mat);
void al_pos(Lista* li, int pos);
int al_rec_eq(Lista* li1, Lista* li2);
void put_pos(Lista* li, int pos, struct aluno al);
int Concatenate_List(Lista* list1, Lista* list2);
void remove_duplicatas(Lista* li);
void fusao_listas_ordenadas(Lista* l1, Lista* l2);
int Troca(Lista* pLista, struct elemento* p);
struct elemento* busca_por_matricula(Lista *li, int mat);

#endif //LISTADIN_H
