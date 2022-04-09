#ifndef LLIST_H
#define LLIST_H
#define T LinkedList
#define N Node

typedef struct N *N;
typedef N T;
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

int llst_isEmpty(T lst);


#undef T
#undef N
#endif
/*
 * 单链表结构
struct N
{
    N *next;
    E elem;
}
// 双链表结构
struct N
{
    N *prev;
    N *next;
    E elem;
};
*/