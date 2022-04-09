#ifndef TREE_H
#define TREE_H
#include "elem.h"
#define T Tree
#define N Node

typedef struct T *T;
typedef struct N *N;
/*
 * 创建和销毁操作
 */
T tree_new (void);
T tree_free(T tree);

/*
 * 基本操作：
 */
void tree_insert (T tree, N x);
void tree_delete (T tree, N x);
N    tree_search (T tree, E e);
N    tree_findMin(T tree);
N    tree_findMax(T tree);

/*
 * 补充方法：
 */
T    tree_clear    (T tree);
void tree_preorder (T tree);
void tree_inorder  (T tree);
void tree_postorder(T tree);

#endif
/*
// 二叉树结构
sturct N
{
    E elem;
    N *left;
    N *right;
}
struct T
{
    int count;
    int depth;
    N *root;
}
*/