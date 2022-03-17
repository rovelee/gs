#include "show.c"
#include <string.h>

int main(){
    // 测试环境：Ubuntu 20.04
    // 十六进制输出为小端输出（little endian）
    // 指针地址为 8 字节

    // 252,645,135(10) 
    // int: 0x0f0f0f0f
    // float: 0xf1f0704d
    printf("test 1: 252645135\n");
    test_show_bytes(252645135);
    // 12345(10)
    // int: 0x39300000
    // float: 00e44046
    printf("test 2: 12345\n");
    test_show_bytes(12345);

    // int x = 252645135;
    // show_int(x);
    // show_float((float) x);
    // show_pointer(&x);

    printf("test 3: 0x12345678\n");
    int val = 0x12345678;
    byte_pointer pval = (byte_pointer) &val;
    show_byte(pval, 1); //78
    show_byte(pval, 2); //7856
    show_byte(pval, 3); //785643

    // 0~9 的ASCII码是 0x30~0x39
    // A~B 的ASCII码是 0x41~0x5A
    // a~b 的ASCII码是 0x61~0x7A
    printf("test 3: 'ABCDEF'\n");
    char *s = "ABCDEF";
    show_byte(s, strlen(s));
}
