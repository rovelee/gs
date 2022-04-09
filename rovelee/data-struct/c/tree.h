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

#endif