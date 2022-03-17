#include <stdio.h>

typedef unsigned char *byte_pointer;
typedef unsigned int *bit_pointer;
/* 小端输出十六进制 */
void show_byte(byte_pointer start, int len)
{
    int i;
    for (i = 0; i < len; i++){
        printf("%.2x", start[i]);
        printf(" ");
    }
    printf("\n");
}
/* 大端输出二进制 */
void show_bit(bit_pointer start, int len)
{
    int i;
    for(i = len - 1; i >= 0; i--){
        printf("%d", (*start & (1 << i)) >> i);
        if(i % 8 == 0 && i > 0)
            printf(" ");
        else if(i % 4 == 0 && i > 0)
            printf(",");    
    }
    printf("\n");
}
void show_bits_int(int x)
{
    show_bit((bit_pointer)&x, sizeof(int)*8);
}

void show_bits_float(float x)
{
    show_bit((bit_pointer)&x, sizeof(float)*8);
}

void show_bits_pointer(void *x)
{
    show_bit((bit_pointer)&x, sizeof(void *)*8);
}
void show_bytes_int(int x)
{
    show_byte((byte_pointer) &x, sizeof(int));
}

void show_bytes_float(float x)
{
    show_byte((byte_pointer) &x, sizeof(float));
}

void show_bytes_pointer(void *x)
{
    show_byte((byte_pointer) &x, sizeof(void*));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    printf("hexadecimal of int:\n");
    show_bytes_int(ival);
    printf("binary of int:\n");
    show_bits_int(ival);
    printf("hexadecimal of float:\n");
    show_bytes_float(fval);
    printf("binary of float:\n");
    show_bits_float(fval);
    printf("hexadecimal of pointer:\n");
    show_bytes_pointer(pval);
    printf("binary of pointer:\n");
    show_bits_pointer(pval);
}