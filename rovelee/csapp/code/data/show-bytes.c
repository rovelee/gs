#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
    int i = 0;
    for (; i < len; i++)
    {
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void show_short(short* s){
    show_bytes((byte_pointer) s, sizeof(short));
}

void show_long(long* l){
    show_bytes((byte_pointer)l,sizeof(long));
}

void show_double(double* d){
    show_bytes((byte_pointer)d,sizeof(double));
}