#include "bit-operator.c"
#include <stdio.h>

int main(){
    int x = 1, y = 9;
    printf("Before: x = %d, y = %d\n", x, y);
    inplace_swap(&x, &y);
    printf("After: x = %d, y = %d\n", x, y);

    int xx = 0x98fdecba, mask = 0x000000FF;

    printf("Before: xx = %x, mask = %x\n", xx, mask);
    printf("bis: %x, bic: %x\n", bis(xx, mask), bic(xx, mask));

}
