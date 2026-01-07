# 📚 IntAVLTree - 整型 AVL 平衡二叉搜索树

> 一个轻量级整型 AVL 树实现（C 语言）

## 🔹 功能概览

- ✅ 支持插入、删除、查找
- ✅ 自动维护平衡性（AVL 性质）
- ✅ 所有操作时间复杂度：**O(log n)**
- ✅ 提供中序遍历回调接口
- ✅ 安全内存释放机制

## 📂 接口说明

| 函数 | 功能 |
|------|------|
| `InsertIntoIntAVLTree(root, value)` | 插入新值，返回新根 |
| `RemoveIntAVLTreeNode(root, value)` | 删除指定值节点，返回新根 |
| `DeleteIntAVLTree(root)` | 递归释放整棵树内存 |
| `InorderTraversal(root, pf)` | 中序遍历，调用回调函数处理节点 |
| `SearchInIntAVLTree(root, object)` | 查找值对应的节点，未找到返回 `NULL` |

## 📌 注意事项

- 本库专为 `int` 类型设计。
- 建议搭配 CMake 构建管理。