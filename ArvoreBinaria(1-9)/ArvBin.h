//
// Created by Pichau on 07/11/2025.
//

#ifndef ARVBIN_H
#define ARVBIN_H

typedef struct element{

    int data;
    struct element *left;
    struct element *right;

} Element;

typedef Element *BinaryTree;

BinaryTree* createBinaryTree();
void freeElement(Element* element);
void freeBinaryTree(BinaryTree *tree);
int insertBinaryTree(BinaryTree *tree, int data);
int removeBinaryTree(BinaryTree *tree, int data);
Element* removeCurrentBinaryTree(Element *element);
int isEmptyBinaryTree(BinaryTree *tree);
int heightBinaryTree(BinaryTree *tree);
int totalElementsBinaryTree(BinaryTree *tree);
int consultBinaryTree(BinaryTree *tree, int data, int *result);
void preOrderBinaryTree(BinaryTree *tree);
void inOrderBinaryTree(BinaryTree *tree);
void postOrderBinaryTree(BinaryTree *tree);

int totalLeafsBinaryTree(BinaryTree *tree);
void printBinaryTree(BinaryTree *tree);
int countAppearancesBinaryTree(BinaryTree *tree, int data);
void printLeafsDecrescent(BinaryTree *tree);
int isEqualBinaryTree(BinaryTree *tree1, BinaryTree *tree2);

#endif //ARVBIN_H
