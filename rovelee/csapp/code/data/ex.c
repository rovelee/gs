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
void test()
{
    printf("reflect test\n");
}
/* 反射 test 函数 */
reflect(test);

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
