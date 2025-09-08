#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PilhaDin.h"

int main() {
    // ------------------ Pilha de alunos ------------------
    struct aluno a[4] = {
        {2,"Andre",9.5,7.8,8.5},
        {4,"Ricardo",7.5,8.7,6.8},
        {1,"Bianca",9.7,6.7,8.4},
        {3,"Ana",5.7,6.1,7.4}
    };

    Pilha* pi = cria_Pilha();
    for (int i = 0; i < 4; i++)
        insere_Pilha(pi, a[i]);

    printf("=== Pilha original ===\n");
    imprime_Pilha(pi);

    Pilha* copiaAlunos = pilha_copia(pi);

    printf("\n=== Pilha copiada ===\n");
    imprime_Pilha(copiaAlunos);

    struct aluno al_maior, al_menor;
    float media_geral;
    if (Estatisticas_Pilha(pi, &al_maior, &al_menor, &media_geral)) {
        printf("\n--- Estatisticas da Pilha ---\n");
        printf("Aluno com MAIOR media: %s (%.2f)\n",
               al_maior.nome,
               (al_maior.n1 + al_maior.n2 + al_maior.n3) / 3.0);
        printf("Aluno com MENOR media: %s (%.2f)\n",
               al_menor.nome,
               (al_menor.n1 + al_menor.n2 + al_menor.n3) / 3.0);
        printf("Media geral da pilha: %.2f\n", media_geral);
    }

    printf("\n=== Comparacao de Pilhas ===\n");
    if (comparar_Pilhas(pi, copiaAlunos))
        printf("As pilhas sao iguais!\n");
    else
        printf("As pilhas sao diferentes!\n");

    int pares, impares;
    contador_pares_impares_Pilha(pi, &pares, &impares);
    printf("Quantidade de matriculas pares: %d\n", pares);
    printf("Quantidade de matriculas impares: %d\n", impares);

    libera_Pilha(pi);
    libera_Pilha(copiaAlunos);

    // ------------------ Pilha de caracteres ------------------
    PilhaChar* piChar = cria_PilhaChar();
    char c;

    char linha[1000];
    printf("\nDigite uma sequencia de caracteres: ");
    fgets(linha, sizeof(linha), stdin); // lê a linha inteira

    // Inserir na pilha ignorando espaços e pontos, e convertendo para minúscula
    for (int i = 0; linha[i] != '\0' && linha[i] != '\n'; i++) {
        if (!isspace(linha[i]) && linha[i] != '.')
            insere_PilhaChar(piChar, tolower(linha[i]));
    }


    // Imprimir invertido
    printf("Texto invertido: ");
    PilhaChar* copiaChar = cria_PilhaChar();
    char temp;
    while(!PilhaChar_vazia(piChar)) {
        consulta_topo_PilhaChar(piChar, &temp);
        printf("%c", temp);
        insere_PilhaChar(copiaChar, temp);
        remove_PilhaChar(piChar);
    }
    printf("\n");

    // Restaurar original
    while(!PilhaChar_vazia(copiaChar)) {
        consulta_topo_PilhaChar(copiaChar, &temp);
        insere_PilhaChar(piChar, temp);
        remove_PilhaChar(copiaChar);
    }
    libera_PilhaChar(copiaChar);

    // Verificar palíndromo
    int palindromo = 1;
    int n = 0;
    char str[1000];
    PilhaChar* tempPi = pilha_copiaChar(piChar); // função similar à pilha_copia
    while(!PilhaChar_vazia(tempPi)) {
        consulta_topo_PilhaChar(tempPi, &str[n++]);
        remove_PilhaChar(tempPi);
    }
    libera_PilhaChar(tempPi);

    for(int i=0; i<n/2; i++) {
        if(str[i] != str[n-1-i]) {
            palindromo = 0;
            break;
        }
    }
    printf(palindromo ? "E palindromo!\n" : "Nao e palindromo.\n");

    libera_PilhaChar(piChar);

    return 0;
}

