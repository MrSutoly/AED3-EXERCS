#include "matriz.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void limparTela() {
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif
    setlocale(LC_ALL, "pt_BR.UTF-8");

#ifdef _WIN32
    system("cls");
#else
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
#endif
}

void esperarEnter() {
    printf("\nPressione ENTER para continuar...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
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
    printf("5. Transpor Matriz \n");
    printf("6. Rotacionar 90 Graus Horária\n");
    printf("7. Rotacionar 90 Graus Anti-Horária\n");
    printf("8. Inserir/Atualizar Valor (Linha, Coluna, Valor)\n");
    printf("9. Consultar Valor\n");
    printf("10. Consultar Vizinhos de um Nó\n");
    printf("11. Verificar se a Matriz é Simétrica\n"); // ← NOVA OPÇÃO
    printf("0. Sair e Desalocar\n");
    printf("---------------------------\n");
    printf("Escolha uma opção: ");
}

int main() {
    Matriz *m = NULL;
    int opcao, linhas, colunas, valor, l, c;
    int ch;

    limparTela();
    printf("--- INICIALIZAÇÃO DA MATRIZ ---\n");

    printf("Digite o número inicial de linhas: ");
    if (scanf("%d", &linhas) != 1 || linhas <= 0) { linhas = 3; }

    printf("Digite o número inicial de colunas: ");
    if (scanf("%d", &colunas) != 1 || colunas <= 0) { colunas = 3; }

    while ((ch = getchar()) != '\n' && ch != EOF);

    m = alocarMatriz(linhas, colunas);
    printf("Matriz %dx%d criada.\n", linhas, colunas);

    if (linhas >= 2 && colunas >= 2) {
        inserirValor(m, 0, 0, 11);
        inserirValor(m, 0, 1, 12);
        inserirValor(m, 1, 0, 21);
        inserirValor(m, 1, 1, 22);
    }

    do {
        limparTela();
        imprimirMatrizAtual(m);
        exibirMenu();

        if (scanf("%d", &opcao) != 1) {
            opcao = -1;
        }
        while ((ch = getchar()) != '\n' && ch != EOF);

        switch (opcao) {
            case 1:
                printf("Executando: Adicionar Linha\n");
                printf("Em qual posição (1 a %d) deseja adicionar a linha? ", m->linhas + 1);
                scanf("%d", &l);
                while ((ch = getchar()) != '\n' && ch != EOF);
                addRow(m, l);
                printf("\nResultado: Linha adicionada na posição %d.\n", l);
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 2:
                printf("Executando: Adicionar Coluna\n");
                printf("Em qual posição (1 a %d) deseja adicionar a coluna? ", m->colunas + 1);
                scanf("%d", &c);
                while ((ch = getchar()) != '\n' && ch != EOF);
                addColumn(m, c);
                printf("\nResultado: Coluna adicionada na posição %d.\n", c);
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 3:
                printf("Executando: Remover Linha\n");
                printf("Qual linha (1 a %d) deseja remover? ", m->linhas);
                scanf("%d", &l);
                while ((ch = getchar()) != '\n' && ch != EOF);
                removeRow(m, l);
                printf("\nResultado: Linha %d removida.\n", l);
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 4:
                printf("Executando: Remover Coluna\n");
                printf("Qual coluna (1 a %d) deseja remover? ", m->colunas);
                scanf("%d", &c);
                while ((ch = getchar()) != '\n' && ch != EOF);
                removeColumn(m, c);
                printf("\nResultado: Coluna %d removida.\n", c);
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 5:
                printf("Executando: Transposição (In-Place).\n");
                transporMatriz(m);
                printf("Resultado: Transposição concluída.\n");
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 6:
                printf("Executando: Rotação 90 Graus HORÁRIA.\n");
                rotacionar90GrausHoraria(m);
                printf("Resultado: Rotação Horária concluída.\n");
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 7:
                printf("Executando: Rotação 90 Graus ANTI-HORÁRIA.\n");
                rotacionar90GrausAntiHoraria(m);
                printf("Resultado: Rotação Anti-Horária concluída.\n");
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 8:
                printf("Executando: Inserir/Atualizar Valor\n");
                printf("Linha (1 a %d): ", m->linhas);
                scanf("%d", &l);
                while ((ch = getchar()) != '\n' && ch != EOF);
                printf("Coluna (1 a %d): ", m->colunas);
                scanf("%d", &c);
                while ((ch = getchar()) != '\n' && ch != EOF);
                printf("Valor: ");
                scanf("%d", &valor);
                while ((ch = getchar()) != '\n' && ch != EOF);
                inserirValor(m, l - 1, c - 1, valor);
                printf("\nResultado: Valor %d inserido em (%d, %d).\n", valor, l, c);
                imprimirMatrizAtual(m);
                esperarEnter();
                break;
            case 9:
                printf("Executando: Consultar Valor\n");
                printf("Linha (1 a %d): ", m->linhas);
                scanf("%d", &l);
                while ((ch = getchar()) != '\n' && ch != EOF);
                printf("Coluna (1 a %d): ", m->colunas);
                scanf("%d", &c);
                while ((ch = getchar()) != '\n' && ch != EOF);
                valor = lerValor(m, l - 1, c - 1);
                if (valor != -99999)
                    printf("\nResultado: O valor na posição (%d, %d) é: %d\n", l, c, valor);
                else
                    printf("\nResultado: Posição (%d, %d) inválida.\n", l, c);
                esperarEnter();
                break;
            case 10:
                printf("Executando: Consultar Vizinhos\n");
                printf("Linha (1 a %d): ", m->linhas);
                scanf("%d", &l);
                while ((ch = getchar()) != '\n' && ch != EOF);
                printf("Coluna (1 a %d): ", m->colunas);
                scanf("%d", &c);
                while ((ch = getchar()) != '\n' && ch != EOF);
                printf("\nResultado: Vizinhos do nó (%d, %d):\n", l, c);
                imprimirVizinhos(m, l - 1, c - 1);
                esperarEnter();
                break;
            case 11: // ← NOVA OPÇÃO: verificar simetria
                printf("Executando: Verificar Simetria da Matriz\n");
                if (matrizSimetrica(m))
                    printf("\n✅ A matriz É SIMÉTRICA.\n");
                else
                    printf("\n❌ A matriz NÃO é simétrica.\n");
                imprimirMatrizAtual(m);
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

    desalocarMatriz(m);
    printf("Matriz desalocada com sucesso!\n");
    return 0;
}
