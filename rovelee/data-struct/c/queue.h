#ifndef QUEUE_H
#define QUEUE_H
#include "elem.h"
#define T Queue

typedef struct T *T;

T    que_new    (void);
int  que_isEmpty(T que);
int  que_isFull (T que);
void enqueue    (T que, void *x);
E    dequeue    (T que);
void que_free   (T que);

#undef T
#endif
/*
 * 使用数组实现队列
#define QUEUE_MAX_SIZE 5
struct T
{
    int head;
    int tail;
    const int length = QUEUE_MAX_SIZE;
    E   array[lenth];
}
*/