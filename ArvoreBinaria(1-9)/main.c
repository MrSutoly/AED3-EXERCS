#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ArvBin.h"

int main() {
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif
    setlocale(LC_ALL, "pt_BR.UTF-8");

#ifdef _WIN32
    system("cls");
#else
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
#endif


    int dados_analise[8] = {50, 100, 30, 20, 40, 45, 35, 37};
    int quant_analise = 8;

    BinaryTree* tree_analise = createBinaryTree();

    for (int i = 0; i < quant_analise; i++) {
        insertBinaryTree(tree_analise, dados_analise[i]);
    }

    printf("## Testes de Análise da Arvore ##\n");
    printf("1. Total de folhas: %d\n", totalLeafsBinaryTree(tree_analise));
    printf("\n2. Printando a árvore :\n");
    printBinaryTree(tree_analise);

    int number = 50;
    printf("\n\n3. Aparicoes do numero %d: %d\n", number, countAppearancesBinaryTree(tree_analise, number));

    printf("\n4. Printando as folhas em ordem decrescente:\n");
    printLeafsDecrescent(tree_analise);

    freeBinaryTree(tree_analise);


    printf("\n ## Teste da Funcao de Igualdade (isEqualBinaryTree) ##\n");

    int dados1[] = {50, 100, 30, 20, 40, 45, 35, 37, 50, 40, 50};
    int quant_dados1 = 11;
    int dados2[] = {50, 100, 30, 20, 40, 45, 35, 37, 50, 40, 50};
    int quant_dados2 = 11;
    int dados3[] = {50, 100, 30, 20, 40, 45, 35, 37, 50, 40, 51};
    int quant_dados3 = 11;

    BinaryTree* tree1 = createBinaryTree();
    BinaryTree* tree2 = createBinaryTree();
    BinaryTree* tree3 = createBinaryTree();

    for (int i = 0; i < quant_dados1; i++) {
        insertBinaryTree(tree1, dados1[i]);
    }
    for (int i = 0; i < quant_dados2; i++) {
        insertBinaryTree(tree2, dados2[i]);
    }
    for (int i = 0; i < quant_dados3; i++) {
        insertBinaryTree(tree3, dados3[i]);
    }

    printf("5a. Comparando tree1 e tree2 (Iguais esperados):\n");
    if (isEqualBinaryTree(tree1, tree2)) {
        printf("-> As árvores tree1 e tree2 são IGUAIS.\n\n");
    } else {
        printf("-> As árvores tree1 e tree2 são DIFERENTES.\n\n");
    }

    printf("5b. Comparando tree1 e tree3 (Diferentes esperados):\n");
    if (isEqualBinaryTree(tree1, tree3)) {
        printf("-> As árvores tree1 e tree3 são IGUAIS.\n\n");
    } else {
        printf("-> As árvores tree1 e tree3 são DIFERENTES.\n\n");
    }

    freeBinaryTree(tree1);
    freeBinaryTree(tree2);
    freeBinaryTree(tree3);

    BinaryTree *tree = createBinaryTree();

    insertBinaryTree(tree, 'M');
    insertBinaryTree(tree, 'F');
    insertBinaryTree(tree, 'S');
    insertBinaryTree(tree, 'D');
    insertBinaryTree(tree, 'J');
    insertBinaryTree(tree, 'P');
    insertBinaryTree(tree, 'U');
    insertBinaryTree(tree, 'A');
    insertBinaryTree(tree, 'E');
    insertBinaryTree(tree, 'H');
    insertBinaryTree(tree, 'Q');
    insertBinaryTree(tree, 'T');
    insertBinaryTree(tree, 'W');
    insertBinaryTree(tree, 'K');

    printf("\nÁrvore em ordem:\n");
    printTreeAsChar(tree);

    ExprNode *root = buildExpressionTree();

    printf("\nInfixa:   ");
    printInfix(root);

    printf("\nPrefixa:  ");
    printPrefix(root);

    printf("\nPosfixa:  ");
    printPostfix(root);

    printf("\n\nResultado da expressão: %d\n", evalExpressionTree(root));


    freeBinaryTree(root);
    freeBinaryTree(tree);
    return 0;
}