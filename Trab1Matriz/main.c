
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para limpar a tela
void limparTela() {
#ifdef _WIN32
    // Comando para Windows
    system("cls");
#else
    // Simulação de limpeza para maior portabilidade
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
#endif
}

// Função auxiliar para esperar o usuário pressionar Enter
void esperarEnter() {
    printf("\nPressione ENTER para continuar...");

    // **SOLUÇÃO FINAL:**
    // 1. Limpa qualquer lixo que possa ter restado no buffer do scanf anterior.
    // Isso garante que a próxima leitura não consuma um '\n' antigo.
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    // 2. Agora, lê um novo caractere, forçando o programa a esperar a entrada do usuário.
    // Isto garante a pausa.
    getchar();
}

void imprimirMatrizAtual(Matriz *m) {
    if (m == NULL) {
        printf("\n[MATRIZ VAZIA]");
        return;
    }
    printf("\n--- MATRIZ ATUAL (%dx%d) ---\n", m->linhas, m->colunas);
    imprimirMatriz(m);
    printf("---------------------------\n");
}

void exibirMenu() {
    printf("\n--- MENU DE OPERAÇÕES ---\n");
    printf("1. Adicionar Linha\n");
    printf("2. Adicionar Coluna\n");
    printf("3. Remover Linha\n");
    printf("4. Remover Coluna\n");
    printf("5. Transpor Matriz (In-Place)\n");
    printf("6. Rotacionar 90 Graus Horária\n");
    printf("7. Rotacionar 90 Graus Anti-Horária\n");
    printf("8. Inserir/Atualizar Valor (Linha, Coluna, Valor)\n");
    printf("9. Consultar Valor\n");
    printf("10. Consultar Vizinhos de um Nó\n");
    printf("0. Sair e Desalocar\n");
    printf("---------------------------\n");
    printf("Escolha uma opção: ");
}

int main() {
    Matriz *m = NULL;
    int opcao, linhas, colunas, valor, l, c;
    int ch; // Variável para limpeza de buffer

    limparTela();
    printf("--- INICIALIZAÇÃO DA MATRIZ ---\n");

    printf("Digite o número inicial de linhas: ");
    if (scanf("%d", &linhas) != 1 || linhas <= 0) { linhas = 3; }

    printf("Digite o número inicial de colunas: ");
    if (scanf("%d", &colunas) != 1 || colunas <= 0) { colunas = 3; }

    // LIMPEZA CRÍTICA: Consome o ENTER após a última leitura de coluna
    while ((ch = getchar()) != '\n' && ch != EOF);

    m = alocarMatriz(linhas, colunas);

    printf("Matriz %dx%d criada.\n", linhas, colunas);

    // Inicialização da matriz com valores de exemplo
    if (linhas >= 2 && colunas >= 2) {
        inserirValor(m, 0, 0, 11);
        inserirValor(m, 0, 1, 12);
        inserirValor(m, 1, 0, 21);
        inserirValor(m, 1, 1, 22);
    }


    do {
        // 1. Limpa a tela e exibe o estado atual da matriz e o menu
        limparTela();
        imprimirMatrizAtual(m);
        exibirMenu();

        // 2. Lê a opção
        if (scanf("%d", &opcao) != 1) {
            opcao = -1; // Opção inválida
        }

        // LIMPEZA CRÍTICA: Consome o ENTER após a leitura da opção
        while ((ch = getchar()) != '\n' && ch != EOF);

        // O switch executa a operação, imprime o resultado e chama esperarEnter()

        switch (opcao) {
            case 1: // Adicionar Linha
                printf("Executando: Adicionar Linha\n");
                printf("Em qual posição (1 a %d) deseja adicionar a linha? ", m->linhas + 1);
                scanf("%d", &l);
                while ((ch = getchar()) != '\n' && ch != EOF); // Limpeza de buffer

                addRow(m, l);
                printf("\nResultado: Linha adicionada na posição %d.\n", l);
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 2: // Adicionar Coluna
                printf("Executando: Adicionar Coluna\n");
                printf("Em qual posição (1 a %d) deseja adicionar a coluna? ", m->colunas + 1);
                scanf("%d", &c);
                while ((ch = getchar()) != '\n' && ch != EOF); // Limpeza de buffer

                addColumn(m, c);
                printf("\nResultado: Coluna adicionada na posição %d.\n", c);
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 3: // Remover Linha
                printf("Executando: Remover Linha\n");
                printf("Qual linha (1 a %d) deseja remover? ", m->linhas);
                scanf("%d", &l);
                while ((ch = getchar()) != '\n' && ch != EOF); // Limpeza de buffer

                removeRow(m, l);
                printf("\nResultado: Linha %d removida.\n", l);
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 4: // Remover Coluna
                printf("Executando: Remover Coluna\n");
                printf("Qual coluna (1 a %d) deseja remover? ", m->colunas);
                scanf("%d", &c);
                while ((ch = getchar()) != '\n' && ch != EOF); // Limpeza de buffer

                removeColumn(m, c);
                printf("\nResultado: Coluna %d removida.\n", c);
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 5: // Transpor
                printf("Executando: Transposição (In-Place). Dimensões (%dx%d) -> (%dx%d).\n", m->linhas, m->colunas, m->colunas, m->linhas);
                transporMatriz(m);
                printf("Resultado: Transposição concluída.\n");
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 6: // Rotacionar Horária
                printf("Executando: Rotação 90 Graus HORÁRIA. Dimensões (%dx%d) -> (%dx%d).\n", m->linhas, m->colunas, m->colunas, m->linhas);
                rotacionar90GrausHoraria(m);
                printf("Resultado: Rotação Horária concluída.\n");
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 7: // Rotacionar Anti-Horária
                printf("Executando: Rotação 90 Graus ANTI-HORÁRIA. Dimensões (%dx%d) -> (%dx%d).\n", m->linhas, m->colunas, m->colunas, m->linhas);
                rotacionar90GrausAntiHoraria(m);
                printf("Resultado: Rotação Anti-Horária concluída.\n");
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 8: // Inserir Valor
                printf("Executando: Inserir/Atualizar Valor\n");
                printf("Linha (1 a %d): ", m->linhas);
                scanf("%d", &l);
                while ((ch = getchar()) != '\n' && ch != EOF); // Limpeza de buffer

                printf("Coluna (1 a %d): ", m->colunas);
                scanf("%d", &c);
                while ((ch = getchar()) != '\n' && ch != EOF); // Limpeza de buffer

                printf("Valor: ");
                scanf("%d", &valor);
                while ((ch = getchar()) != '\n' && ch != EOF); // Limpeza de buffer FINAL

                inserirValor(m, l - 1, c - 1, valor);
                printf("\nResultado: Valor %d inserido em (%d, %d).\n", valor, l, c);
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 9: // Consultar Valor
                printf("Executando: Consultar Valor\n");
                printf("Linha (1 a %d): ", m->linhas);
                scanf("%d", &l);
                while ((ch = getchar()) != '\n' && ch != EOF); // Limpeza de buffer

                printf("Coluna (1 a %d): ", m->colunas);
                scanf("%d", &c);
                while ((ch = getchar()) != '\n' && ch != EOF); // Limpeza de buffer FINAL

                valor = lerValor(m, l - 1, c - 1);
                if (valor != -99999) {
                    printf("\nResultado: O valor na posição (%d, %d) é: %d\n", l, c, valor);
                } else {
                     printf("\nResultado: Posição (%d, %d) inválida ou nó inexistente.\n", l, c);
                }
                esperarEnter();
                break;
            case 10: // Consultar Vizinhos
                printf("Executando: Consultar Vizinhos\n");
                printf("Linha (1 a %d): ", m->linhas);
                scanf("%d", &l);
                while ((ch = getchar()) != '\n' && ch != EOF); // Limpeza de buffer

                printf("Coluna (1 a %d): ", m->colunas);
                scanf("%d", &c);
                while ((ch = getchar()) != '\n' && ch != EOF); // Limpeza de buffer FINAL

                printf("\nResultado: Vizinhos do nó (%d, %d):\n", l, c);
                imprimirVizinhos(m, l - 1, c - 1);
                esperarEnter();
                break;
            case 0:
                printf("\nSaindo do programa.\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
                esperarEnter();
                break;
        }

    } while (opcao != 0);

    // Limpeza final
    desalocarMatriz(m);
    printf("Matriz desalocada com sucesso!\n");
    return 0;
}
