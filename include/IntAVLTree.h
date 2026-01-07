/**
* @file    IntAVLTree.h
* @brief   int类型AVL树实现
* @author  pzjw0066
* @date    2025/01/07
*/

#ifndef INTAVLTREE_H
#define INTAVLTREE_H

/**
* @brief AVL树节点
*/
typedef struct IntAVLTreeNode
{
    struct IntAVLTreeNode *left, *right; /**< 左右孩子节点 */
    int height; /**< 树的高度 */
    int value; /**< 存储的值 */
}IntAVLTreeNodeStruct;

/**
* @brief 将新节点插入到AVL树中
* @param root 树的根节点
* @param value 要插入的节点存储的值
* @return 插入后树的新根节点
*/
IntAVLTreeNodeStruct *InsertIntoIntAVLTree(IntAVLTreeNodeStruct *root, int value);

/**
* @brief 将某节点从AVL树中移除
* @param root 树的根节点
* @param value 要移除的节点存储的值
* @return 移除后树的新根节点
*/
IntAVLTreeNodeStruct *RemoveIntAVLTreeNode(IntAVLTreeNodeStruct *root, int value);

/**
* @brief 在内存中将整个树删除，即删除树中所有节点
* @param root 树的根节点
* @note 删除后不可再使用此节点！
*/
void DeleteIntAVLTree(IntAVLTreeNodeStruct *root);

/**
* @brief 对AVL树进行中序遍历
* @param root 树的根节点
* @param pf 遍历时调用的回调函数
*/
void InorderTraversal(IntAVLTreeNodeStruct *root, void (*pf)(IntAVLTreeNodeStruct*));

/**
* @brief 在AVL树中查找值所对应的节点
* @param root 树的根节点
* @param object 要查找的值
* @return 值所对应的节点
*/
IntAVLTreeNodeStruct *SearchInIntAVLTree(IntAVLTreeNodeStruct *root, int object);

#endif