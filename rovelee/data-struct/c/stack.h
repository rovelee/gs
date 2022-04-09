#ifndef STACK_H
#define STACK_H
#include "elem.h"
#define T Stack

typedef struct T *T;
/*
 * 创建和销毁操作
 */
T     stk_new    (void);
void  stk_free   (T *stk);
/*
 * 基本操作：
 */
void  push       (T stk, void *x);
E     pop        (T stk);
/*
 * 补充方法：
 */
int   stk_isEmpty(T stk);
T     stk_clear  (T stk);
void  stk_show   (T stk);

#undef T
#endif
/*
// 以链表实现栈
struct T
{
    int count;
    struct elem
    {
        void *x;
        struct elem *link;
    } *head;
}

//以数组实现栈
#define STACK_MAX_SIZE 5
struct T
{
    int top;
    int count;
    E list[STACK_MAX_SIZE];
}
*/