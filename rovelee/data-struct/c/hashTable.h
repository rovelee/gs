#ifndef HASHTABLE_H
#define HASHTABLE_H

#define T HashTable
#define N Node
#define K Key

typedef struct T   *T;
typedef struct N   *N;
typedef const char *K;

/*
 * 创建和销毁操作
 */
T hash_new (int size);
T hash_free(T ht);

/*
 * 基本操作：
 */
void hash_insert (T ht, K key);
void hash_delete (T ht, K key);
N    hash_search (T ht, K key);
/*
 * 补充方法：
 */
T hash_clear(T ht);
// 散列函数
typedef unsigned int index;
index hashing(K key, int size);

#undef T
#undef N
#undef K
#endif
/*
// 连接法散列表结构：
#define MAX_HASH_TABLE_SIZE 47 // m的取值最好是一个不太接近2的整数幂的素数
struct N
{
    N *next;
    K key;
};
struct T
{
    const int size = MAX_HASH_TABLE_SIZE;
    N *table[size];
};
// 直接寻址表：槽k -> 全域U，略
// 除法散列法：
index hashing(K key, int size)
{
    // h(k) = key mod size
    unsigned int hv;
    int base：
    hv = 0;
    base = 7;
    // 将关键字转换为自然数，以 2^7 (128) 为基数
    while(*key!='\0')
        hv = (hv << base) + *key++;
    return hv % size;
};
// 乘法散列法：
#include <limits.h>
#define HASH_RATIO 2654435769
#define HASH_BIT_LENGTH 14
index hashing(K key, int size)
{
    // h(k) = floor(size*(key*A mod 1))
    // 假设机器字长 w = 32，依据 Knuth 的建议。 A取根号下5-1的差除以2
    // A = s/2^w，于是 s = A * 2^32 = 2 654 435 769
    // k*s = (r1 * 2^32) + r0 得到 r0
    // 散列值取 p 位，r0 右移 (32-p) 位得到散列值

    const unsigned int w = INT_MAX;
    const unsigned int s = HASH_RATIO;
    const unsigned int p = HASH_BIT_LENGTH;
    unsigned int hv;

    // 将关键字转换为自然数，以 2^7 (128) 为基数
    base = 7;
    while(*key!='\0')
        hv = (hv << base) + *key++;

    return (hv * s) << (w - p);
}
*/