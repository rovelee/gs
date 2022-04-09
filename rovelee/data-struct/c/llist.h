#ifndef LLIST_H
#define LLIST_H
#define T LinkedList
#define N Node

typedef struct T *T;
typedef struct N *N;
/*
 * 创建和销毁操作
 */
T    llst_new   (void);
void llst_free  (T lst);
/*
 * 基本操作：
 */
N    llst_search(T lst, int k);
void llst_insert(T lst, N x);
void llst_delete(T lst, N x);
/*
 * 补充方法：
 */
int  llst_isEmpty(T lst);
int  llst_isLast (T lst, N x);
N    llst_head   (T lst);
N    llst_tail   (T lst);
T    llst_clear  (T lst);
void llst_show   (T lst);

#undef T
#undef N
#endif
/*
// 单链表结构
struct N
{
    N *next;
    E elem;
};
struct T
{
    int length;
    N *head;
};
// 双链表结构
struct N
{
    N *prev;
    N *next;
    E elem;
};

struct T
{
    int length;
    N *head;
    N *tail;
}

//哨兵双循环列表
struct T
{
    int length;
    N *nil;
}
*/