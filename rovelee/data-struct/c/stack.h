#ifndef STACK_H
#define STACK_H
#include "elem.h"
#define T Stack

typedef struct T *T;

T     stk_new    (void);
int   stk_isEmpty(T stk);
E     pop        (T stk);
void  push       (T stk, void *x);
void  stk_free   (T *stk);

#undef T
#endif
/*
 * 接口实现
 * 以链表实现栈
struct T
{
    int count;
    struct elem
    {
        void *x;
        struct elem *link;
    } *head;
}
 *
 * 以数组实现栈
 *
#define STACK_MAX_SIZE 5
struct T
{
    int top;
    int count;
    E list[STACK_MAX_SIZE];
}
/*