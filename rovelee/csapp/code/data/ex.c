#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 定义一个数据结构，包含函数名和一个无参函数指针 */
struct foo
{
    void (*fn)();
    const char *name;
};
/*
    定义一个宏定义函数 reflect，通过 gcc 的内置函数 attribute 设置一个叫做 foos 的“段”来放置 foo 的数据结构。
    这个宏定义函数能够将一个函数通过加载进 foo 的数据结构中，以此来建立函数名和函数之间的映射。
 */
#define reflect(x) __attribute__((section("foos"))) struct foo _##x = {x, #x};
/* 一个用以测试的函数 */
void ex0()
{
    printf("reflect test\n");
}
/* 反射该测试函数 */
reflect(ex0);

/* 课后代码习题 */

/* show_bytes 函数，使用强制类型转换来访问和打印程序数据的字节表示 */
typedef char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)ival;
    int *pval = &val;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}
/* 练习题 2.5 */
void ex5()
{
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer)&val;
    show_bytes(valp, 1); /* A. 21 */
    show_bytes(valp, 2); /* B. 2143 */
    show_bytes(valp, 3); /* C. 214365 */
}
reflect(ex5);
/* 练习题 2.10 */
void inplace_swap(int *x, int *y)
{
    printf("---inplace_swap---\n");
    show_pointer((byte_pointer)x);
    show_pointer((byte_pointer)y);

    printf("y := %d ^ %d = ", *x, *y);
    *y = *x ^ *y;
    printf("%d\n", *y);

    printf("x := %d ^ %d = ", *x, *y);
    *x = *x ^ *y;
    printf("%d\n", *x);

    printf("y := %d ^ %d = ", *x, *y);
    *y = *x ^ *y;
    printf("%d\n", *y);
}
void istest()
{
    int x = 3, y = 3;
    inplace_swap(&x, &y);
}
reflect(istest);

void ex10()
{
    int x = 1, y = 2;
    printf("x = %d, y = %d\n", x, y);
    inplace_swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
}
reflect(ex10);
/* 练习题 2.11 */
void reverse_array(int a[], int cnt)
{
    printf("***reverse_array***\n");
    int first, last;
    for (first = 0, last = cnt - 1;
         first <= last; // change this line
                        /*
                          The Anser of B:
                          当 a[fisrt] 和 a[last] 的地址相同时，inplace_swap(a[first], a[last]) 中总是两个相同的值在异或，所以它们总是0。
                      */
                        //  first < last; // after change, answer of C.
         first++, last--)
        inplace_swap(&a[first], &a[last]);
    printf("first = %d, last = %d\n", first - 1, last + 1);
}
void ex11()
{
    printf("###ex11###\n");
    int even_array[4] = {1, 2, 3, 4};
    int odd_array[5] = {1, 2, 3, 4, 5};

    reverse_array(even_array, 4);
    reverse_array(odd_array, 5);

    printf("----print here----\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", even_array[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", odd_array[i]);
    }
    printf("\n");
}
reflect(ex11);
/* 练习题27 */
/* 如果 x 和 y 相加不会溢出，这个函数就返回 1 */
int uadd_ok(unsigned x, unsigned y)
{
    int is_overflow;
    is_overflow = x > (x + y) || y > (x + y);
    return !is_overflow;
}
void ex27()
{
    unsigned x, y;
    x = 1 << 31;
    y = 1 << 31;
    show_int(x);
    show_int(y);
    printf("%u + %u = %u\n", x, y, x + y);
    printf("%d\n", uadd_ok(x, y)); // 1表示没有溢出，0表示溢出
}
reflect(ex27);
/* 练习题30 */
/* 如果 x 和 y 相加不会溢出，这个函数就返回 1 */
int tadd_ok(int x, int y)
{
    if (x > 0 && y > 0 && x + y <= 0)
        return 0;
    if (x < 0 && y < 0 && x + y >= 0)
        return 0;
    return 1;
}
void ex30()
{
    int x, y;
    x = 1 << 31;
    y = -1;
    printf("%d + %d = %d\n", x, y, x + y);
    printf("%d - %d = %d\n", x + y, x, x + y - x);
    printf("%d\n", tadd_ok(x, y)); // 1表示没有溢出，0表示溢出
    x = 1 << 30;
    y = x;
    printf("%d + %d = %d\n", x, y, x + y);
    printf("%d - %d = %d\n", x + y, x, x + y - x);
    printf("%d\n", tadd_ok(x, y)); // 1表示没有溢出，0表示溢出
}
reflect(ex30);
/* 练习题32 */
int tsub_ok(int x, int y)
{
    // return tadd_ok(x, -y); // buggy code.
    // 注意 TMin （补码最小数）的非是它本身。当被减数等于 TMin 时结果等于 2^w + x， 是一定溢出的。
    int TMin = 1 << 31;
    return (y == TMin) ? 0 : tadd_ok(x, -y);
}
void ex32()
{
    int x, y;
    x = 1;
    y = 1 << 31;
    printf("%d%d = %d\n", x, -y, x - y);
    printf("%d\n", tsub_ok(x, y)); // 1表示没有溢出，0表示溢出
}
reflect(ex32);
/* 以下代码禁止使用（测试代码除外）
    1、条件语句、循环、分支语句、函数调用、和宏调用。
    2、除法、模运算和乘法。
    3、相对比较运算。
*/
/* 61 */
void ex61()
{
    int x1 = -1;
    int x2 = 0;
    int x3 = 0xff;
    int x4 = ~0xff;

    printf("x:%d, A:%d, B:%d, C:%d, D:%d\n", x1, !(x1 ^ -1), !(x1 ^ 0), !((x1 & 0xff) ^ 0xff), !((x1 & 0xff) ^ 0));
    printf("x:%d, A:%d, B:%d, C:%d, D:%d\n", x2, !(x2 ^ -1), !(x2 ^ 0), !((x2 & 0xff) ^ 0xff), !((x2 & 0xff) ^ 0));
    printf("x:%d, A:%d, B:%d, C:%d, D:%d\n", x3, !(x3 ^ -1), !(x3 ^ 0), !((x3 & 0xff) ^ 0xff), !((x3 & 0xff) ^ 0));
    printf("x:%d, A:%d, B:%d, C:%d, D:%d\n", x4, !(x4 ^ -1), !(x4 ^ 0), !((x4 & 0xff) ^ 0xff), !((x4 & 0xff) ^ 0));
}
reflect(ex61);
/* 62 */
int int_shifts_are_arithmetic()
{
    return !((-1 >> (sizeof(int) * 8 - 1)) ^ -1);
}
void ex62()
{
    printf("%d\n", int_shifts_are_arithmetic());
}
reflect(ex62);
/* 63、 solve code 中禁用右移和除法，srl 返回逻辑右移 k 位的 x，sra返回算术右移 k 位的 x*/
unsigned srl(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int)x >> k;
    /* solve code */
    int w = 8 * sizeof(int);
    unsigned mask = ~(-1 << (w - k));
    return mask & xsra;
}
int sra(int x, int k)
{
    /* Perform shift logically */
    int xsrl = (unsigned)x >> k;
    /* solve code */
    int w = 8 * sizeof(int);
    int s = !!(x & (1 << (w - 1)) ^ 0);
    // printf("%d\n",s);
    unsigned mask = ((~s + 1) << (w - k));
    // printf("%x",mask);
    return mask | xsrl;
}
void ex63()
{
    int x = -1;
    int x2 = 0;
    int x3 = 0xff;
    int x4 = ~0xff;
    int k = 16;
    printf("srl test: %x, sra test: %x\n", srl(x, k) == ((unsigned)x >> k), sra(x, k) == (x >> k));
    printf("srl test: %x, sra test: %x\n", srl(x2, k) == ((unsigned)x2 >> k), sra(x2, k) == (x2 >> k));
    printf("srl test: %x, sra test: %x\n", srl(x3, k) == ((unsigned)x3 >> k), sra(x3, k) == (x3 >> k));
    printf("srl test: %x, sra test: %x\n", srl(x4, k) == ((unsigned)x4 >> k), sra(x4, k) == (x4 >> k));
}
reflect(ex63);

int main(int argc, char const *argv[])
{
    /*
        引入全局变量 __start_foos 和 __stop_foos，这两个变量是之前宏定义中的 __attribute__((section("foos"))) 创建的，
        命名规则是 __start_<段名> 和 __stop_<段名>，分别代表了段中的第一个 reflect 产生的数据————之前定义的数据结构 foo，
        和一个作为结束的空数据，这段数据结构组成了一个 foo 的线表，以 __stop_foos 的首地址作为结束地址。
    */
    extern struct foo __start_foos;
    extern struct foo __stop_foos;

    /* 通过循环查找 foos 段中的函数名，然后执行函数名对应的函数，通过这种方式完成了一次“反射” */
    for (struct foo *f = &__start_foos; f < &__stop_foos; f++)
    {
        if (strcmp(f->name, argv[1]) == 0)
            f->fn();
    }

    return 0;
}
