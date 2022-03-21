#include <stdio.h>
#include <limits.h>
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
    unsigned w1 = 127, w2 = 128, w3 = 255, w4 = 256;
    printf("%u %d %d\n", w1, fun1_ex221(w1), fun2_ex221(w1));
    printf("%u %d %d\n", w2, fun1_ex221(w2), fun2_ex221(w2));
    printf("%u %d %d\n", w3, fun1_ex221(w3), fun2_ex221(w3));
    printf("%u %d %d\n", w4, fun1_ex221(w4), fun2_ex221(w4));
}

void ex222()
{
    unsigned le = 0;
    printf("0 - 1 (unsigned) = %u\n", le - 1);
}

void ex237()
{
    int ix = INT_MAX;
    float fx = 1.0;
    double dx = __FLT_MAX__;
    int a, b, c, d, e, f, g, h;
    a = ix == (int)(float)ix; //单精度能表示的最大整数是 2^24，而整形最大的数是 2^31，所以 a=0
    b = ix == (int)(double)ix;
    c = fx == (float)(double)fx;
    d = dx == (float)d; // 双精度大于单精度最大值时，舍去一半后的数不等。
    e = fx == -(-fx);
    f = 2 / 3 == 2 / 3.0; // 整形舍入整形，不等于浮点数
    g = (dx >= 0.0) || ((dx * 2) < 0.0);
    h = (dx + fx) - dx == fx; // 舍入会导致fx丢失
    printf("a:%d b:%d c:%d d:%d e:%d f:%d g:%d h:%d\n", a, b, c, d, e, f, g, h);
}

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
    return (word >> (bytenum << 3)) & 0xff;
}

int xxbyte(packed_t word, int bytenum)
{
    int lm = (int)(sizeof(int) * 8 - 8);
    return ((int)((word >> (bytenum << 3)) & 0xff) << lm) >> lm;
}

void ex246()
{
    packed_t x = 0xff00;
    int xx = xbyte(x, 1);
    show_bytes_int(xx);
    printf("%d\n", xx);
    xx = xxbyte(x, 1);
    show_bytes_int(xx);
    printf("%d\n", xx);
}

#include "show-bytes.c"

void ex238()
{
    int tx = 3;
    show_bytes((byte_pointer)&tx, sizeof(tx));
    tx = 333333;
    show_bytes((byte_pointer)&tx, sizeof(tx));
}

void ex240()
{
    short sx = 30;
    long lx = 3000;
    double dx = 10201.0;
    show_short(&sx);
    show_long(&lx);
    show_double(&dx);
}

int is_little_endian()
{
    /* 如果第一个字节是1，则说明是小端机器，其他字节都为0，所以如果是大端机器，则返回0*/
    int x = 1;
    byte_pointer first_byte = (byte_pointer)&x;
    return *first_byte;
}

void ex241()
{
    printf("这台电脑是%s端机器\n", is_little_endian() == 1 ? "小" : "大");
}

int generate_a_word(int x, int y)
{
    /* 生成一个字，由x的最低字节和y中的剩余字节组成 */
    return (x & 0xff) | (y & (-1 << 8));
}

void ex242()
{
    int a = generate_a_word(0x89abcdef, 0x76543210);
    show_bytes_int(a); // 76 54 32 ef
}

int ex242_a(int x)
{
    unsigned ux = x;
    int result = 1, le = sizeof(int) * 8 - 1;
    for (int i = 0; i <= le; i++)
    {
        int cb = (((ux >> i) << le) >> le);
        result = result && cb;
    }
    return result;
}
int ex242_b(int x)
{
    unsigned ux = x;
    int result = 0, le = sizeof(int) * 8 - 1;
    for (int i = 0; i <= le; i++)
    {
        int cb = (((ux >> i) << le) >> le);
        result = result || cb;
    }
    return !result;
}
int ex242_c(int x)
{
    unsigned ux = x;
    int result = 0, le = sizeof(int) * 8 - 1;
    for (int i = 8; i <= le; i++)
    {
        int cb = (((ux >> i) << le) >> le);
        result = result || cb;
    }
    if ((result = !result))
    {
        for (int i = 0; i < 8; i++)
            result = result && (((ux >> i) << le) >> le);
    }
    return result;
}
int ex242_d(int x)
{
    unsigned ux = x;
    int result = 0, le = sizeof(int) * 8 - 1;
    for (int i = 0; i < 8; i++)
    {
        int cb = (((ux >> i) << le) >> le);
        // show_bits_int(cb);
        result = result || cb;
    }
    if ((result = !result))
    {
        for (int i = 8; i < le; i++)
            result = result && (((ux >> i) << le) >> le);
    }
    return result;
}
void ex243()
{
    /* 只使用位级运算和逻辑运算在下列条件下产生1，而在其他情况下产生0 */
    int x1, x2, x3, x4;

    x1 = -1;
    // show_bytes_int(x1);
    x2 = 0;
    // show_bytes_int(x2);
    x3 = 0xff;
    // show_bytes_int(x3);
    x4 = -1 << 8;
    // show_bytes_int(x4);
    /* A、x的任何位都等于1*/
    int r1, r2, r3, r4;
    r1 = ex242_a(x1);
    r2 = ex242_a(x2);
    r3 = ex242_a(x3);
    r4 = ex242_a(x4);
    printf("A、a(%.2x)=%d a(%.2x)=%d a(%.2x)=%d a(%.2x)=%d\n", x1, r1, x2, r2, x3, r3, x4, r4);
    /* B、x的任何位都等于0*/
    r1 = ex242_b(x1);
    r2 = ex242_b(x2);
    r3 = ex242_b(x3);
    r4 = ex242_b(x4);
    printf("B、a(%.2x)=%d a(%.2x)=%d a(%.2x)=%d a(%.2x)=%d\n", x1, r1, x2, r2, x3, r3, x4, r4);
    /* C、x的最低字节都为1*/
    r1 = ex242_c(x1);
    r2 = ex242_c(x2);
    r3 = ex242_c(x3);
    r4 = ex242_c(x4);
    printf("C、a(%.2x)=%d a(%.2x)=%d a(%.2x)=%d a(%.2x)=%d\n", x1, r1, x2, r2, x3, r3, x4, r4);
    /* D、x的最低字节都为0*/
    r1 = ex242_d(x1);
    r2 = ex242_d(x2);
    r3 = ex242_d(x3);
    r4 = ex242_d(x4);
    printf("D、a(%.2x)=%d a(%.2x)=%d a(%.2x)=%d a(%.2x)=%d\n", x1, r1, x2, r2, x3, r3, x4, r4);
}