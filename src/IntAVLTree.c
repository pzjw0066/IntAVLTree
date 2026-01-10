#include <stdlib.h>
#include "IntAVLTree.h"

// 获取节点的高度属性（NULL节点的是-1）
static inline int GetHeight(const IntAVLTreeNodeStruct *root)
{
    if (!root)
        return -1;

    return root->height;
}

// 更新节点的高度属性
static inline void UpdateHeight(IntAVLTreeNodeStruct *root)
{
    int left_height = GetHeight(root->left), right_height = GetHeight(root->right);

    root->height = (left_height > right_height ? left_height : right_height) + 1;
}

// 计算节点的平衡因子
static inline int GetBalanceFactor(const IntAVLTreeNodeStruct *root)
{
    return root ? GetHeight(root->left) -  GetHeight(root->right) : 0;
}

// AVL节点的构造函数
static inline IntAVLTreeNodeStruct *CreateIntAVLTreeNode(const int value)
{
    IntAVLTreeNodeStruct *node = malloc(sizeof(IntAVLTreeNodeStruct));

    if (!node)
        return NULL;

    node->left = NULL;
    node->right = NULL;
    node->value = value;

    node->height = 0;

    return node;
}

// 右旋
static inline IntAVLTreeNodeStruct *RightRotate(IntAVLTreeNodeStruct *root)
{
    IntAVLTreeNodeStruct *child = root->left, *grand_child = child->right;

    child->right = root;
    root->left = grand_child;
    
    UpdateHeight(root);
    UpdateHeight(child);

    return child;
}

// 左旋
static inline IntAVLTreeNodeStruct *LeftRotate(IntAVLTreeNodeStruct *root)
{
    IntAVLTreeNodeStruct *child = root->right, *grand_child = child->left;

    child->left = root;
    root->right = grand_child;

    UpdateHeight(root);
    UpdateHeight(child);

    return child;
}

// 通过节点的平衡因子自动选择合适的旋转方式
static IntAVLTreeNodeStruct *Rotate(IntAVLTreeNodeStruct *root)
{
    int balance_factor = GetBalanceFactor(root);

    // L_型
    if (balance_factor > 1)
    {
        // LL型
        if (GetBalanceFactor(root->left) >= 0)
            return RightRotate(root);
        // LR型
        else
        {
            root->left = LeftRotate(root->left);
            return RightRotate(root);
        }
    }

    // R_型
    if (balance_factor < -1)
    {
        // RR型
        if (GetBalanceFactor(root->right) <= 0)
            return LeftRotate(root);
        // RL型
        else
        {
            root->right = RightRotate(root->right);
            return LeftRotate(root);
        }
    }

    return root;
}

IntAVLTreeNodeStruct *InsertIntoIntAVLTree(IntAVLTreeNodeStruct *root, const int value)
{
    if (!root)
        return CreateIntAVLTreeNode(value);

    if (root->value == value)
        return root;
    else if (root->value > value)
        root->left = InsertIntoIntAVLTree(root->left, value);
    else
        root->right = InsertIntoIntAVLTree(root->right, value);

    UpdateHeight(root);

    return Rotate(root);
}

IntAVLTreeNodeStruct *RemoveIntAVLTreeNode(IntAVLTreeNodeStruct *root, const int value)
{
    if (!root)
        return NULL;

    if (root->value == value)
    {
        IntAVLTreeNodeStruct *child;

        // root节点至少有一个NULL节点，即root节点的度可能为0或1
        if (!root->left || !root->right)
        {
            child = NULL;

            child = root->right ? root->right : NULL;
            
            // 度为0，直接删除，即返回NULL节点
            if (!child)
                return NULL;
            
            // 度为1，将本身替换成孩子节点，即返回孩子节点（之后需更新高度）
            root = child;
        }
        // root节点的度为2
        else
        {
            // 查找中序遍历的下一个节点
            child = root->right;
            while (child->left)
                child = child->left;

            // 把其值赋给根节点的右子节点，并递归删除此节点
            int child_val = child->value;
            root->right = RemoveIntAVLTreeNode(root->right, child_val);
            root->value = child_val;
        }
    }
    else if (root->value > value)
        root->left = RemoveIntAVLTreeNode(root->left, value);
    else
        root->right = RemoveIntAVLTreeNode(root->right, value);

    UpdateHeight(root);

    return Rotate(root);
}

void DeleteIntAVLTree(IntAVLTreeNodeStruct *root)
{
    if (!root)
        return;

    DeleteIntAVLTree(root->left);
    DeleteIntAVLTree(root->right);
    free(root);
}

void InorderTraversal(const IntAVLTreeNodeStruct *root, void (*pf)(const IntAVLTreeNodeStruct*))
{
    if (!root)
        return;

    InorderTraversal(root->left, pf);
    pf(root);
    InorderTraversal(root->right, pf);
}

const IntAVLTreeNodeStruct *SearchInIntAVLTree(const IntAVLTreeNodeStruct *root, const int object)
{
    while (root)
    {
        if (root->value == object)
            break;

        root = root->value > object ? root->left : root->right;
    }

    return root;
}