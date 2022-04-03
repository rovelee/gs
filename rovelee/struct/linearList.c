#include <stdio.h>
#include <stdlib.h>
/*
 * 线性表：
 *  线性表是由 n 个连续存储单元组成的顺序结构，
 *
 *
 */
/* 定义元素类型 */
typedef int etype;
/* 定义线性表结构 */
struct linearList
{
    etype *head; // 头指针
    int size;    // 表大小
    int length;  // 元素个数
};
/* 定义一个线性表数据类型的类型 table */
typedef struct linearList table;
/* 初始化一个长度为 n 的线性表 */
table initTable(int n)
{
    table t;
    t.head = (etype *)malloc(n * sizeof(etype));
    if (!t.head) // 如果头指针为空，则创建失败退出
    {
        printf("初始化失败\n");
        exit(0);
    }
    t.size = n;
    t.length = 0;

    return t;
}
/*
 * 顺序表插入元素
 * 在表 t 中第 n 个下标位置插入元素 e
 */
table addTable(table t, etype e, int n)
{
    //判断插入位置是否正确，如果不正确则提示退出
    if (n > t.length || n < 0)
    {
        printf("插入位置超出当前长度或小于0\n");
        return t;
    }
    //判断空间是否足够容纳一个新元素，如果不够重新分配空间大小
    if (t.length == t.size)
    {
        t.head = (etype *)realloc(t.head, (t.size + 1) * sizeof(etype));
        if (!t.head)
        {
            printf("存储分配失败\n");
            return t;
        }
        t.size++;
    }
    //插入操作，需要将插入位置后的元素都后移一位
    for (int i = t.length - 1; i >= n; i--)
        t.head[i + 1] = t.head[i];

    t.head[n] = e;
    t.length++;
    return t;
}
/*
 * 顺序表删除元素
 * 根据下标删除第 n 位的元素
 */
table delTable(table t, int n)
{
    //判断删除位置是否正确，如果不正确则提示退出
    if (n > t.length || n < 0)
    {
        printf("该元素不存在\n");
        return t;
    }
    //使 n-1 位元素的后继等于第 n+1 位的元素
    for (int i = n; i <= t.length - 1; i++)
        t.head[i] = t.head[i + 1];
    t.length--;
    return t;
}
/*
 * 顺序表查找元素
 * 返回元素下标
 */
int findTable(table t, etype e)
{
    for (int i = 0; i < t.length; i++)
        if (t.head[i] == e)
            return i;

    return -1;
}
/*
 * 修改顺序表
 * 修改第n位的值为 e
 */
table updTable(table t, etype e, int n)
{
    if (n > t.length || n < 0)
    {
        printf("该元素不存在\n");
        return t;
    }
    t.head[n] = e;

    return t;
}
/* 输出线性表中的内容 */
void displayTable(table t)
{
    for (int i = 0; i < t.length; i++)
        printf("%d ", t.head[i]);
    printf("\n");
    printf("size=%d, length=%d\n", t.size, t.length);
}

/* 测试输出 */
#define Size 5
int main()
{
    int i;
    table t = initTable(Size);
    //向顺序表中添加元素
    for (i = 0; i < Size; i++)
    {
        // t.head[i - 1] = i;
        // t.length++;
        t = addTable(t, i, i);
    }
    printf("顺序表中存储的元素分别是：\n");
    displayTable(t);
    //向顺序表中插入元素
    printf("在顺序表中第%d位插入元素%d\n", i + 1, i);
    t = addTable(t, i, i);
    displayTable(t);
    printf("在顺序表中第%d位插入元素%d\n", 0, -1);
    t = addTable(t, -1, 0);
    displayTable(t);
    //删除第一个元素
    printf("删除第一个元素\n");
    t = delTable(t, 0);
    displayTable(t);
    //删除最后一个元素
    printf("删除最后个元素\n");
    t = delTable(t, t.length - 1);
    displayTable(t);
    //查找元素 4
    int e = 4;
    i = findTable(t, e);
    printf("%d位于表中的第%d位\n", e, i);
    //查找元素 99是否不存在
    e = 99;
    i = findTable(t, e);
    printf("%d%s\n", e, i > -1 ? "位于表中" : "不在表中");
    //修改第0位为99
    printf("修改第0位为99\n");
    t = updTable(t, 99, 0);
    displayTable(t);
    //查找元素 99 是否存在
    e = 99;
    i = findTable(t, e);
    printf("%d%s\n", e, i > -1 ? "位于表中" : "不在表中");

    return 0;
}