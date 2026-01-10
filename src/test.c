#include <stdio.h>
#include "IntAVLTree.h"

static void PrintNode(const IntAVLTreeNodeStruct *node)
{
    printf("%d ", node->value);
}

int main(void)
{
    IntAVLTreeNodeStruct *root = NULL;

    root = InsertIntoIntAVLTree(root, 1);
    root = InsertIntoIntAVLTree(root, 2);
    root = InsertIntoIntAVLTree(root, 3);
    root = InsertIntoIntAVLTree(root, 4);
    root = InsertIntoIntAVLTree(root, 5);
    root = InsertIntoIntAVLTree(root, 5);

    InorderTraversal(root, PrintNode);
    putchar('\n');

    RemoveIntAVLTreeNode(root, 4);

    InorderTraversal(root, PrintNode);
    putchar('\n');

    DeleteIntAVLTree(root);
}