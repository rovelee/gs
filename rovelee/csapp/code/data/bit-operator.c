void inplace_swap(int *x, int * y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

/* Bit Set */
int bis(int x, int m)
{
    int result = x | m;
    return result;
}

/* Bit Clear */
int bic(int x, int m)
{
    int result = x & m;
    return result;
}
