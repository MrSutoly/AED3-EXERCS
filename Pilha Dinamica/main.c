#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

int main() {
    Pilha* pi = NULL;
    PilhaChar* piChar = NULL;
    struct aluno al;
    int opcao, pares, impares, n;
    char linha[1000], c;

    do {
        menu();
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1: // Inicializa pilha
                if(pi != NULL) libera_Pilha(pi);
                pi = cria_Pilha();
                printf("Pilha inicializada.\n");
                break;

            case 2: // Verifica se pilha vazia
                printf(Pilha_vazia(pi) ? "Pilha vazia.\n" : "Pilha nao esta vazia.\n");
                break;

            case 3: // Verifica se pilha cheia
                printf(Pilha_cheia(pi) ? "Pilha cheia.\n" : "Pilha nao esta cheia.\n");
                break;

            case 4: // Empilha elemento
                printf("Digite matricula: ");
                scanf("%d", &al.matricula);
                getchar();
                printf("Digite nome: ");
                fgets(al.nome, 30, stdin);
                al.nome[strcspn(al.nome, "\n")] = 0;
                printf("Digite 3 notas: ");
                scanf("%f %f %f", &al.n1, &al.n2, &al.n3);
                insere_Pilha(pi, al);
                printf("Aluno inserido.\n");
                break;

            case 5: // Desempilha elemento
                printf("Deseja remover quantos elementos? ");
                scanf("%d", &n);
                desempilha_n(n-1, pi); // desempilha_n desempilha n+1, ajustei
                printf("%d elementos removidos.\n", n);
                break;

            case 6: // Lê topo da pilha
                if(consulta_topo_Pilha(pi, &al))
                    printf("Topo da pilha: %d - %s\n", al.matricula, al.nome);
                else
                    printf("Pilha vazia.\n");
                break;

            case 7: // Estatísticas da pilha
                if(Estatisticas_Pilha(pi, &al, &al, &al.n1)) {
                    struct aluno maior, menor; float media;
                    Estatisticas_Pilha(pi, &maior, &menor, &media);
                    printf("Maior media: %s\nMenor media: %s\nMedia geral: %.2f\n",
                           maior.nome, menor.nome, media);
                } else printf("Pilha vazia.\n");
                break;

            case 8: // Contar pares e impares
                contador_pares_impares_Pilha(pi, &pares, &impares);
                printf("Pares: %d, Impares: %d\n", pares, impares);
                break;

            case 9: // Copiar pilha
                {
                    Pilha* copia = pilha_copia(pi);
                    printf("Pilha copiada:\n");
                    imprime_Pilha(copia);
                    libera_Pilha(copia);
                }
                break;

            case 10: // Comparar pilhas
                {
                    Pilha* copia = pilha_copia(pi);
                    printf(comparar_Pilhas(pi, copia) ? "Pilha iguais\n" : "Pilha diferentes\n");
                    libera_Pilha(copia);
                }
                break;

            case 11: // Push2
                {
                    struct aluno al1, al2;
                    printf("Aluno 1: matricula, nome, notas: ");
                    scanf("%d", &al1.matricula); getchar();
                    fgets(al1.nome,30,stdin); al1.nome[strcspn(al1.nome,"\n")] = 0;
                    scanf("%f %f %f", &al1.n1, &al1.n2, &al1.n3);

                    printf("Aluno 2: matricula, nome, notas: ");
                    scanf("%d", &al2.matricula); getchar();
                    fgets(al2.nome,30,stdin); al2.nome[strcspn(al2.nome,"\n")] = 0;
                    scanf("%f %f %f", &al2.n1, &al2.n2, &al2.n3);

                    push2(pi, al1, al2);
                }
                break;

            case 12: // Pop2
                pop2(pi);
                printf("Dois elementos removidos do topo.\n");
                break;

            case 13: // Verifica string xCy
                printf("Digite sequencia do tipo xCy: ");
                fgets(linha, sizeof(linha), stdin);
                linha[strcspn(linha,"\n")] = 0;
                printf(verifica(linha) ? "Valida!\n" : "Invalida!\n");
                break;

            case 14: // Pilha de caracteres (palindromo)
                if(piChar != NULL) libera_PilhaChar(piChar);
                piChar = cria_PilhaChar();
                printf("Digite string: ");
                fgets(linha, sizeof(linha), stdin);
                linha[strcspn(linha,"\n")] = 0;
                for(int i=0; linha[i]; i++)
                    if(!isspace(linha[i]) && linha[i]!='.')
                        insere_PilhaChar(piChar, tolower(linha[i]));
                {
                    PilhaChar* copiaChar = pilha_copiaChar(piChar);
                    int pal = 1, len = 0;
                    char str[1000];
                    while(!PilhaChar_vazia(copiaChar)) {
                        consulta_topo_PilhaChar(copiaChar, &str[len++]);
                        remove_PilhaChar(copiaChar);
                    }
                    libera_PilhaChar(copiaChar);
                    for(int i=0;i<len/2;i++)
                        if(str[i]!=str[len-1-i]) pal=0;
                    printf(pal?"E palindromo!\n":"Nao e palindromo.\n");
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    libera_Pilha(pi);
    if(piChar != NULL) libera_PilhaChar(piChar);

    return 0;
}
