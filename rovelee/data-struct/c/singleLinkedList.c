#include "llist.h"
#include "elem.h"
#include <stdlib.h>
#define T LinkedList
#define N Node

// 单链表结构
struct N
{
    N *next;
    E elem;
};

typedef struct N *N;
typedef N T;

/*
 * 创建和销毁操作
 */
N node_init()
{
    N node = (N)malloc(sizeof(N));
    return node;
}
T llst_new(void)
{
    return node_init();
}
void llst_free(T lst)
{
    N p = lst;
    while (p)
    {
        lst = lst->next;
        free(p);
        p = lst;
    }
}

/*
 * 基本操作：
 */
N llst_search(T lst, int k)
{
    int i;
    N p = lst;
    for (i = 0; i < k; i++)
        p = p->next;
    return p;
}
void llst_insert(T lst, N x)
{
    if (!lst)
    {
        lst = x;
        return lst;
    }
    N p = lst;
    while (p->next)
        p = p->next;
    p->next = x;
    return lst;
}
void llst_delete(T lst, N x)
{
    if (!lst)
        return lst;
    N p = lst;
    if (p == x)
    {
        lst = lst->next;
        free(p);
    }
    while (p->next && p->next != x)
        p = p->next;
    if (!p->next)
        return;
    N n = p->next;
    p->next = n->next;
    free(n);
}

/*
 * 补充方法：
 */
int llst_isEmpty(T lst);
int llst_isLast(T lst, N x);
N llst_head(T lst);
N llst_tail(T lst);
T llst_clear(T lst);
void llst_show(T lst);

#undef T
#undef N
