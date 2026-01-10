#ifndef INTAVLTREE_H
#define INTAVLTREE_H

// AVL树节点
typedef struct IntAVLTreeNode
{
    struct IntAVLTreeNode *left, *right; // 左右孩子节点
    int height;                          // 树的高度
    int value;                           // 存储的值
}IntAVLTreeNodeStruct;

IntAVLTreeNodeStruct *InsertIntoIntAVLTree(IntAVLTreeNodeStruct *root, int value);                // 将新节点插入到AVL树中，返回插入后的新根节点
IntAVLTreeNodeStruct *RemoveIntAVLTreeNode(IntAVLTreeNodeStruct *root, int value);                // 将某节点从AVL树中移除，返回删除后的新根节点
void DeleteIntAVLTree(IntAVLTreeNodeStruct *root);                                                // 在内存中将整个树删除，即删除树中所有节点。注意：删除后不可再使用此节点！
void InorderTraversal(const IntAVLTreeNodeStruct *root, void (*pf)(const IntAVLTreeNodeStruct*)); // 对AVL树进行中序遍历，pf是遍历时调用的函数
const IntAVLTreeNodeStruct *SearchInIntAVLTree(const IntAVLTreeNodeStruct *root, int object);                 // 在AVL树中查找值所对应的节点

#endif