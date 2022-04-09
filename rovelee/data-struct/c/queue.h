#ifndef QUEUE_H
#define QUEUE_H
#include "elem.h"
#define T Queue

typedef struct T *T;
/*
 * 创建和销毁操作
 */
T    que_new    (void);
void que_free   (T que);
/*
 * 基本操作：
 */
void enqueue    (T que, void *x);
E    dequeue    (T que);
/*
 * 补充方法：
 */
int  que_isEmpty(T que);
int  que_isFull (T que);
void que_clear  (T que);
E    que_getHead(T que);
E    que_getTail(T que);
void que_show   (T que);

#undef T
#endif
/*
// 使用数组实现队列
#define QUEUE_MAX_SIZE 5
struct T
{
    int head;
    int tail;
    const int length = QUEUE_MAX_SIZE;
    E   array[lenth];
}
*/