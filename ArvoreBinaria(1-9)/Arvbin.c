//
// Created by Pichau on 07/11/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "ArvBin.h"

BinaryTree* createBinaryTree() {

    BinaryTree *tree = (BinaryTree *) malloc(sizeof(BinaryTree));
    if (tree != NULL) {
        *tree = NULL;
    }
    return tree;

}

void freeElement(Element* element) {

    if (element == NULL) {
        return;
    }
    freeElement(element->left);
    freeElement(element->right);
    free(element);
    element = NULL;

}


void freeBinaryTree(BinaryTree *tree) {

    if (tree == NULL) {
        return;
    }
    freeElement(*tree);
    free(tree);
}

int insertBinaryTree(BinaryTree *tree, int data) {

    if (tree == NULL) {
        return 0;
    }

    Element* newElement = (Element*) malloc(sizeof(Element));
    if (newElement == NULL) {
        return 0;
    }

    newElement->data = data;
    newElement->left = NULL;
    newElement->right = NULL;

    if (*tree == NULL) {
        *tree = newElement;
        return 1;
    }

    Element *current = *tree;
    Element *previous = NULL;

    while (current != NULL) {

        previous = current;
        if (data == current->data) {
            freeElement(newElement);
            return 0;
        }

        if (data > current->data) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    if (data > previous->data) {
        previous->right = newElement;

    } else {
        previous->left = newElement;
    }
    return 1;

}

int removeBinaryTree(BinaryTree *tree, int data) {

    if (tree == NULL) {
        return 0;
    }

    Element *previous = NULL;
    Element *current = *tree;

    while (current != NULL) {

        if (data == current->data) {

            if (current == *tree) {
                *tree = removeCurrentBinaryTree(current);
            }

            else {

                if (previous->right == current) {
                    previous->right = removeCurrentBinaryTree(current);

                } else {
                    previous->left = removeCurrentBinaryTree(current);
                }
            }
            return 1;
        }

        previous = current;
        if(data > current->data)
            current = current->right;
        else
            current = current->left;
    }
    return 0;
}

Element* removeCurrentBinaryTree(Element *element) {

    Element *no1, *no2;

    if (element->left == NULL) {
        no2 = element->right;
        free(element);
        return no2;
    }

    no1 = element;
    no2 = element->left;

    while (no2->right != NULL) {
        no1 = no2;
        no2 = no2->right;
    }

    if (no1 != element) {
        no1->right = no2->left;
        no2->left = element->left;
    }

    no2->right = element->right;
    free(element);
    return no2;

}

int isEmptyBinaryTree(BinaryTree *tree) {

    if (tree == NULL || *tree == NULL) {
        return 1;
    }

    return 0;
}

int heightBinaryTree(BinaryTree *tree) {

    if (tree == NULL || *tree == NULL) {
        return 0;
    }

    int left_height = heightBinaryTree(&(*tree)->left);
    int right_height = heightBinaryTree(&(*tree)->right);
    if (left_height > right_height) {
        return left_height + 1;
    }
    return right_height + 1;

}

int totalElementsBinaryTree(BinaryTree *tree) {
    if (tree == NULL || *tree == NULL)
        return 0;

    return 1 + totalElementsBinaryTree(&(*tree)->left) + totalElementsBinaryTree(&(*tree)->right);
}


int consultBinaryTree(BinaryTree *tree, int data, int *result) {

    if (isEmptyBinaryTree(tree)) {
        return 0;

    }

    if ((*tree)->data == data) {
        *result = (*tree)->data;
        return 1;
    }

    if (consultBinaryTree(&(*tree)->left, data, result)) return 1;
    if (consultBinaryTree(&(*tree)->right, data, result)) return 1;

    return 0;
}


void preOrderBinaryTree(BinaryTree *tree) {

    if (tree == NULL) {
        return;
    }
    if (*tree != NULL) {
        printf("%d\n", (*tree)->data);
        preOrderBinaryTree(&(*tree)->left);
        preOrderBinaryTree(&(*tree)->right);
    }
}

void inOrderBinaryTree(BinaryTree *tree) {

    if (tree == NULL) {
        return;
    }
    if (*tree != NULL) {
        inOrderBinaryTree(&(*tree)->left);
        printf("%d\n", (*tree)->data);
        inOrderBinaryTree(&(*tree)->right);
    }

}

void postOrderBinaryTree(BinaryTree *tree) {

    if (tree == NULL) {
        return;
    }
    if (*tree != NULL) {
        postOrderBinaryTree(&(*tree)->left);
        postOrderBinaryTree(&(*tree)->right);
        printf("%d\n", (*tree)->data);
    }

}

int totalLeafsBinaryTree(BinaryTree *tree) {

    if (tree == NULL || *tree == NULL) { //Se o elemento não existir
        return 0;
    }

    if (isEmptyBinaryTree(&(*tree)->left) && isEmptyBinaryTree(&(*tree)->right)) { //Se o elemento a esquerda e o elemento a direita estiverem vazios significa que é nó folha
        return 1;
    }

    return totalLeafsBinaryTree(&(*tree)->left) + totalLeafsBinaryTree(&(*tree)->right); //Recursividade para buscar todos os nós folhas.

}

void printBinaryTree(BinaryTree *tree) {

    if (tree == NULL) {
        return;
    }

    if (*tree != NULL) {

        if (!isEmptyBinaryTree(&(*tree)->left) || !isEmptyBinaryTree(&(*tree)->right)) {
            printf("\n\nNó pai: %d", (*tree)->data);

            if (!isEmptyBinaryTree(&(*tree)->left)) {
                printf(", Filho a esquerda: %d", (*tree)->left->data);
            }

            if (!isEmptyBinaryTree(&(*tree)->right)) {
                printf(", Filho a direita: %d", (*tree)->right->data);
            }

        } else if (isEmptyBinaryTree(&(*tree)->left) && isEmptyBinaryTree(&(*tree)->right)) {
            printf("\nNó folha: %d\n", (*tree)->data);
        }
        printBinaryTree(&(*tree)->left);
        printBinaryTree(&(*tree)->right);

    }

}

int countAppearancesBinaryTree(BinaryTree *tree, int data) {

    if (tree == NULL || *tree == NULL) {
        return 0;
    }

    if ((*tree)->data == data) { //Se achou o número, procura a direita dele
        return 1 + countAppearancesBinaryTree(&(*tree)->right, data);
    }

    return countAppearancesBinaryTree(&(*tree)->right, data) + countAppearancesBinaryTree(&(*tree)->left, data);
}
// Apenas é necessário verificar a subárvore a direita do último, já que os números iguais
// sempre vão ficar a direita do ultimo numero igual

void printLeafsDecrescent(BinaryTree *tree) {

    if (tree == NULL) {
        return;
    }

    if (*tree != NULL) {

        printLeafsDecrescent(&(*tree)->right);
        if (isEmptyBinaryTree(&(*tree)->left) && isEmptyBinaryTree(&(*tree)->right)) {
            printf("%d\n", (*tree)->data);
        }
        printLeafsDecrescent(&(*tree)->left);

    }

}

int isEqualBinaryTree(BinaryTree *tree1, BinaryTree *tree2) {

    if (isEmptyBinaryTree(tree1) && isEmptyBinaryTree(tree2)) { //Se as duas estiverem vazias, são iguais
        return 1;
    }

    if (isEmptyBinaryTree(tree1) || isEmptyBinaryTree(tree2)) { //Se uma estiver vazia e a outra não, são diferentes
        return 0;
    }

    if (heightBinaryTree(tree1) != heightBinaryTree(tree2)) { //Se a altura das árvores são diferentes
        return 0;
    }

    if (totalElementsBinaryTree(tree1) != totalElementsBinaryTree(tree2)) { //Se a quantidade de elementos são diferentes
        return 0;
    }

    if ((*tree1)->data != (*tree2)->data) { //Se os elementos forem diferentes, retorna 0
        return 0;
    }

    if (isEqualBinaryTree(&(*tree1)->left, &(*tree2)->left) && isEqualBinaryTree(&(*tree1)->right, &(*tree2)->right)) { //Verifica igualdade para as subarvores a esquerda e a direita
        return 1;
    }
    return 0;
}

/* a função verifica para a árvore e depois subárvores os casos que fariam elas
 * diferentes, caso n ache nada, ela passa e sai como igual, retornando 1. */
