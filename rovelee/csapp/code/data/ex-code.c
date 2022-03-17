#include <stdio.h>
#include "show.c"

void fn2_ex213(char *msg, int x)
{
    printf("%s", msg);
    printf("%x\n", x);
    show_bits_int(x);
    printf("\n");
}

void ex213()
{
    int x = 0x66; // 0110 0110
    int y = 0x93; // 1001 0011
    printf("ex 2.13:\n");
    fn2_ex213("x & y = ", x & y);     // 000...0000 0010
    fn2_ex213("x | y = ", x | y);     // 000...1111 0111
    fn2_ex213("~x | ~y = ", ~x | ~y); // 111...1111 1101
    /* 所有的非零参数的布尔值都为1 */
    fn2_ex213("x & !y = ", x & !y);     // 0
    fn2_ex213("x && y = ", x && y);     // 1
    fn2_ex213("x || y = ", x || y);     // 1
    fn2_ex213("!x || !y = ", !x || !y); // 0
    fn2_ex213("x && ~y = ", x && ~y);   // 1
}

int fn0_ex214(int x, int y)
{
    return x == y;
}
int fn1_ex214(int x, int y)
{
    return (!x || y) && (!y || x);
}
void ex214()
{
    int x1 = 1, y1 = 1, x2 = 0, y2 = 0;
    printf("ex 2.14:\n");
    /* x == y 等价与 非x 蕴含 y 与上 非y 蕴含 x*/
    printf("f0 is x == y.\n");
    printf("f1 is (!x || y) && (!y || x).\n");
    printf("x\ty\tf0\tf1\n");
    printf("%d\t%d\t%d\t%d\t\n", x1, y1, fn0_ex214(x1, y1), fn1_ex214(x1, y1));
    printf("%d\t%d\t%d\t%d\t\n", x1, y2, fn0_ex214(x1, y2), fn1_ex214(x1, y2));
    printf("%d\t%d\t%d\t%d\t\n", x2, y1, fn0_ex214(x2, y1), fn1_ex214(x2, y1));
    printf("%d\t%d\t%d\t%d\t\n", x2, y2, fn0_ex214(x2, y2), fn1_ex214(x2, y2));
}

void ex215()
{
    int x1 = 0xf0, x2 = 0x0f, x3 = 0xcc, x4 = 0x55;
    printf("x = %.2x, x << 3 = %.2x, x >> 2 = %.2x\n", x1, x1 << 3, x1 >> 2);
    printf("x = %.2x, x << 3 = %.2x, x >> 2 = %.2x\n", x2, x2 << 3, x2 >> 2);
    printf("x = %.2x, x << 3 = %.2x, x >> 2 = %.2x\n", x3, x3 << 3, x3 >> 2);
    printf("x = %.2x, x << 3 = %.2x, x >> 2 = %.2x\n", x4, x4 << 3, x4 >> 2);
}

void ex220()
{
    int x1 = -2147483648;
    unsigned ux1 = 2147483648;
    // fn2_ex213("x1 = -2147483648 ", x1);
    // fn2_ex213("ux1 = 2147483648 ", ux1);
    printf("%d == %uU is %d\n", x1, ux1, x1 == ux1);
    int x2 = -2147483647;
    printf("%d < %d is %d\n", x1, x2, x1 < x2);
    unsigned ux2 = (unsigned)x1;
    printf("%u < %d is %d\n", ux2, x2, ux2 < x2);
    printf("%d < %d is %d\n", x2, x1, x2 < x1);
    printf("%u < %u is %d\n", ux2, ux1 - 1, ux2 < ux1 - 1);
}

int fun1_ex221(unsigned word)
{
    return (int)((word << 24) >> 24);
}
int fun2_ex221(unsigned word)
{
    return ((int)word << 24) >> 24;
}

void ex221()
{
    unsigned w1 = 127, w2 = 128, w3=255, w4=256;
    printf("%u %d %d\n", w1,fun1_ex221(w1),fun2_ex221(w1));
    printf("%u %d %d\n", w2,fun1_ex221(w2),fun2_ex221(w2));
    printf("%u %d %d\n", w3,fun1_ex221(w3),fun2_ex221(w3));
    printf("%u %d %d\n", w4,fun1_ex221(w4),fun2_ex221(w4));
}

void ex222(){
    unsigned le = 0;
    printf("0 - 1 (unsigned) = %u\n", le - 1);
}