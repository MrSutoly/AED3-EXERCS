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


typedef struct expr {
    char data;
    struct expr *left;
    struct expr *right;
} ExprNode;


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

void removeEvenValues(BinaryTree *tree);
int areSimilarTrees(BinaryTree *tree1, BinaryTree *tree2);
void printTreeAsChar(BinaryTree *tree);

ExprNode* buildExpressionTree();
int evalExpressionTree(ExprNode *root);
void printInfix(ExprNode *root);
void printPrefix(ExprNode *root);
void printPostfix(ExprNode *root);

#endif //ARVBIN_H
