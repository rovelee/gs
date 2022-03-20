#include <stdio.h>
#define POS_INFINITY 1e400
#define NEG_INFINITY (-POS_INFINITY)
#define NEG_ZERO (-1.0 / POS_INFINITY)

double recip(int denom)
{
    return 1.0 / (double)denom;
}

void do_nothing() {}

void test1(int denom)
{
    double r1, r2;
    int t1, t2;

    r1 = recip(denom);
    r2 = recip(denom);
    t1 = r1 == r2;
    do_nothing();
    t2 = r1 == r2;
    printf("test1 t1: r1 %f %c= r2 %f\n", r1, t1 ? '=' : '!', r2);
    printf("test1 t2: r1 %f %c= r2 %f\n", r1, t2 ? '=' : '!', r2);
}

void test2(int denom)
{
    double r1;
    int t1;

    r1 = recip(denom);
    t1 = r1 == 1.0 / (double)denom;
    printf("test2 t1: r1 %f %c= 1.0/10.0 \n", r1, t1 ? '=' : '!');
}

int main(int argc, char const *argv[])
{
    int ia = 10;
    test1(ia); // 和书中的结果不同，test1两次浮点数测试都没有出错，猜测可能是gcc已经做了优化或者64位系统优化过浮点数了。
    test2(ia); // test2 也不同
    return 0;
}
