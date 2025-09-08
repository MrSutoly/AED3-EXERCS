#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDin.h" 

void menu() {
    printf("\n=== MENU PILHA ===\n");
    printf("1 - Inicializa pilha\n");
    printf("2 - Verifica se a pilha e vazia\n");
    printf("3 - Verifica se a pilha e cheia\n");
    printf("4 - Empilha elemento na pilha\n");
    printf("5 - Desempilha elemento da pilha\n");
    printf("6 - Le topo da pilha\n");
    printf("7 - Converte numero decimal em binario\n");
    printf("8 - Sair\n");
    printf("Escolha uma opcao: ");
}

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}

int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

void desempilha_n(int n, Pilha* pi) {
    for (int i = 0; i <= n; i++) {
        if(pi != NULL) {
            Elem* no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
    }
}

void pop2(Pilha* pi) {
    for (int i = 0; i <= 2; i++) {
        if(pi != NULL) {
            Elem* no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
    }
}

int push2(Pilha* pi, struct aluno al1, struct aluno al2) {
    if(pi == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al1;
    no->prox = (*pi);
    *pi = no;

    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al2;
    no->prox = (*pi);
    *pi = no;
    printf("2 Usuários cadastrados \n");

    return 1;
}

typedef struct carac {
    char dado;
    struct carac* prox;
} Carac;

int verifica(char* str) {
    Carac* topo = NULL;
    int i = 0;

    while(str[i] != '\0' && str[i] != 'C'){
        if(str[i] == 'A' || str[i] == 'B'){
            Carac* novo = (Carac*) malloc(sizeof(Carac));
            novo->dado = str[i];
            novo->prox = topo;
            topo = novo;
        }
        i++;
    }

    if(str[i] != 'C') return 0;
    i++;

    while(str[i] != '\0'){
        if(topo == NULL) return 0;
        char topoPilha = topo->dado;
        Carac* temp = topo;
        topo = topo->prox;
        free(temp);

        if(str[i] != topoPilha){
            return 0;
        }
        i++;
    }

    return (topo == NULL);
}


int remove_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Pilha_cheia(Pilha* pi){
    return 0;
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;
    return 0;
}

void imprime_Pilha(Pilha* pi) {
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}
    Pilha* pilha_copia(Pilha* p) {
        if (p == NULL) return NULL;

        Pilha* copia = cria_Pilha();
        Pilha* aux = cria_Pilha();

        if (copia == NULL || aux == NULL) {
            libera_Pilha(copia);
            libera_Pilha(aux);
            return NULL;
        }

        struct aluno temp;

        // Passo 1: transferir original -> aux
        while (!Pilha_vazia(p)) {
            consulta_topo_Pilha(p, &temp);
            remove_Pilha(p);
            insere_Pilha(aux, temp);
        }

        // Passo 2: restaurar original e encher cópia
        while (!Pilha_vazia(aux)) {
            consulta_topo_Pilha(aux, &temp);
            remove_Pilha(aux);
            insere_Pilha(copia, temp);  // copia
            insere_Pilha(p, temp);      // devolve na original
        }

        libera_Pilha(aux);
        return copia;
    }

/* Criei o cabeçalho. Criei uma função para conseguir a média geral das médias
aritméticas, utilizando de uma soma das notas , para conseguir as médias, e por final,
somando-as para conseguir a média geral.No main, apresentei o aluno com a maior, o
aluno com a menor , e a média geral. */

int Estatisticas_Pilha(Pilha* pi, struct aluno* maior, struct aluno* menor, float* media_geral) {
    if (pi == NULL || *pi == NULL)
        return 0;

    Elem* no = *pi;
    float soma = 0;
    int contador = 0;

    *maior = no->dados;
    *menor = no->dados;

    while (no != NULL) {
        float media_atual = (no->dados.n1 + no->dados.n2 + no->dados.n3) / 3.0;
        soma += media_atual;

        float media_maior = (maior->n1 + maior->n2 + maior->n3) / 3.0;
        float media_menor = (menor->n1 + menor->n2 + menor->n3) / 3.0;

        if (media_atual > media_maior)
            *maior = no->dados;
        if (media_atual < media_menor)
            *menor = no->dados;

        contador++;
        no = no->prox;
    }

    *media_geral = soma / contador;
    return 1;
}

/* A função verifica a validade das pilhas: verifica se estão vazias ou se existem. Após
isso compara os elementos e por fim os dados( Matricula, nome e data ).  */

int comparar_Pilhas(Pilha* pi1, Pilha* pi2) {
    if (pi1 == NULL || pi2 == NULL)
        return 0; // Uma das pilhas não existe

    Pilha* aux1 = pilha_copia(pi1); // Criar cópias temporárias para não alterar as originais
    Pilha* aux2 = pilha_copia(pi2);

    struct aluno al1, al2;
    int iguais = 1;

    while (!Pilha_vazia(aux1) && !Pilha_vazia(aux2)) {
        consulta_topo_Pilha(aux1, &al1);
        consulta_topo_Pilha(aux2, &al2);

        // Comparar todos os campos
        if (al1.matricula != al2.matricula ||
            strcmp(al1.nome, al2.nome) != 0 ||
            al1.n1 != al2.n1 ||
            al1.n2 != al2.n2 ||
            al1.n3 != al2.n3) {
            iguais = 0;
            break;
            }

        remove_Pilha(aux1);
        remove_Pilha(aux2);
    }

    // Se uma pilha acabou antes da outra
    if (!Pilha_vazia(aux1) || !Pilha_vazia(aux2))
        iguais = 0;

    libera_Pilha(aux1);
    libera_Pilha(aux2);

    return iguais;
}

/* Fiz a função para contar os pares e ímpares nos elementos( contar as matrículas).
Tratamento de erro.
Por exemplo, a matrícula 1 passa pela conta verificadora e cai na casa dos ímpares.
*/

int contador_pares_impares_Pilha(Pilha* pi, int* pares, int* impares) {
    if(pi == NULL || *pi == NULL) {
        *pares = 0;
        *impares = 0;
        return 0;
    }

    Elem* no = *pi;
    *pares = 0;
    *impares = 0;

    while(no != NULL) {
        if(no->dados.matricula % 2 == 0) (*pares)++;
        else (*impares)++;
        no = no->prox;
    }

    return *pares + *impares;
}

// ================= Pilha de caracteres =================

/* Separei a pilha de caracteres e suas funções para ficar mais organizado, as logicas das
 funções é a mesma das originais, com a exceção sendo a verificação do palíndromo no main
 , que basicamente vai verificando na ordem oposta se a string é igual */

PilhaChar* cria_PilhaChar() {
    PilhaChar* pi = (PilhaChar*) malloc(sizeof(PilhaChar));
    if(pi != NULL) *pi = NULL;
    return pi;
}

int PilhaChar_vazia(PilhaChar* pi) {
    return (pi == NULL || *pi == NULL);
}

int insere_PilhaChar(PilhaChar* pi, char c) {
    if(pi == NULL) return 0;
    ElemChar* no = (ElemChar*) malloc(sizeof(ElemChar));
    if(no == NULL) return 0;
    no->dado = c;
    no->prox = *pi;
    *pi = no;
    return 1;
}

int remove_PilhaChar(PilhaChar* pi) {
    if(PilhaChar_vazia(pi)) return 0;
    ElemChar* no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int consulta_topo_PilhaChar(PilhaChar* pi, char* c) {
    if(PilhaChar_vazia(pi)) return 0;
    *c = (*pi)->dado;
    return 1;
}

void libera_PilhaChar(PilhaChar* pi) {
    if(pi == NULL) return;
    ElemChar* no;
    while(*pi != NULL) {
        no = *pi;
        *pi = no->prox;
        free(no);
    }
    free(pi);
}

PilhaChar* pilha_copiaChar(PilhaChar* p) {
    if (p == NULL) return NULL;

    PilhaChar* copia = cria_PilhaChar();
    PilhaChar* aux = cria_PilhaChar();
    if (copia == NULL || aux == NULL) return NULL;

    char temp;

    // Passo 1: Transferir original -> aux (inverte)
    while (!PilhaChar_vazia(p)) {
        consulta_topo_PilhaChar(p, &temp);
        remove_PilhaChar(p);
        insere_PilhaChar(aux, temp);
    }

    // Passo 2: Restaurar original e criar cópia
    while (!PilhaChar_vazia(aux)) {
        consulta_topo_PilhaChar(aux, &temp);
        remove_PilhaChar(aux);
        insere_PilhaChar(copia, temp);
        insere_PilhaChar(p, temp); // devolve à original
    }

    libera_PilhaChar(aux);
    return copia;
}