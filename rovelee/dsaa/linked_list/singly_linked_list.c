#include <stdlib.h>
#include "linked_list.h"

/* 定义链表的数据结构 */
struct Node
{
    ElementType Element;
    Position Next;
};

/* 链表ADT的具体实现 */

/* 创建一个空表 */
List MakeEmpty(List L)
{
    if (!L)
        L = (List)malloc(sizeof(List));
    return L;
}

/* 测试一个链表是否是空表 */
int IsEmpty(List L)
{
    return L->Next == NULL;
}

/* 测试当前位置是否是链表的末尾 */
int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

/* Find */
Position Find(ElementType X, List L)
{
    Position P;

    P = L->Next;
    while (P != NULL && P->Next != X)
        P = P->Next;
        
    return P;
}