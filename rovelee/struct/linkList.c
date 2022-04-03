#include <stdio.h>
#include <stdlib.h>
/*
 * 链表：
 *      链表，别名链式存储结构或单链表，用于存储逻辑关系为 "一对一" 的数据。
 * 与顺序表不同，链表不限制数据的物理存储状态，换句话说，使用链表存储的数据元素，
 * 其物理存储位置是随机的。
 *
 */
#ifndef _ELEM_TYPE
#define _ELEM_TYPE 1
/* 定义元素类型 */
typedef int etype;
#endif
/* 链表数据结构 */
struct linkList
{
    etype e;               //数据域
    struct linkList *next; //指针域
};
typedef struct linkList link;
/* 初始化一个不带头结点的链表 */
link *initLinkN(etype elem)
{
    link *p = (link *)malloc(sizeof(link));
    p->e = elem;
    p->next = NULL;
    return p;
}
/* 初始化一个带头结点的链表 */
link *initLink0()
{
    link *p = (link *)malloc(sizeof(link));
    p->next = NULL;
    return p;
}
/* 链表添加后续节点 */
link *addNode(link *pre, link *next)
{
    pre->next = next;
    return next;
}
/* 链表添加后续元素 */
link *addElem(link *l, etype elem)
{
    link *p = initLinkN(elem);
    addNode(l, p);
    return p;
}
/* 插入操作 */
void insertLink(link *head, int k, etype elem)
{
    if (k < 1)
        return;
    int i = 1;
    link *p = head;
    while (i < k && p->next)
    {
        i++;
        p = p->next;
    }
    if (i < k)
        return;
    link *n = p->next;
    addNode(addElem(p, elem), n);
}
/* 删除操作 */
void deleteLink(link *head, int k)
{
    if (k < 1)
        return;
    int i = 1;
    link *p = head;
    while (i < k && p->next)
    {
        i++;
        p = p->next;
    }
    if (i < k)
        return;
    link *n = p->next;
    p->next = n->next;
    free(n);
}
/* 打印链表 */
void displayLink(link *head)
{
    link *p = head;
    if (!p->e)
        p = p->next;
    while (p)
    {
        printf("%d ", p->e);
        p = p->next;
    }
    printf("\n");
}
/* 测试链表 */
int main(int argc, char const *argv[])
{
    link *head = initLink0();
    link *p = head;
    const int Size = 5;
    for (int i = 0; i < Size; i++)
        p = addElem(p, i);
    displayLink(head);
    insertLink(head, 1, 99);
    insertLink(head, 3, 99);
    insertLink(head, 6, 99);
    displayLink(head);
    deleteLink(head, 6);
    deleteLink(head, 3);
    deleteLink(head, 1);
    displayLink(head);

    return 0;
}
