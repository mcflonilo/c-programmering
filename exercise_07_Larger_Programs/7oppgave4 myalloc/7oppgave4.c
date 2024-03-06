//
// Created by lar on 3/5/24.
//
#include <stdio.h>
#include "myalloc.h"
#include <stdlib.h>

int main(void)
{
    int *p;
    char *c;
    double *f;
    p = (int *)myalloc("int T",100,4);
    printf("\n int == %d",p[0]);
    c = (char *)myalloc("char T",100,'x');
    printf("\nchar == %c",c[0]);
    f = (double *)myalloc("float T",100, 4.4);
    printf("\nfloat == %f",f[0]);

    free(p);
    free(c);
    free(f);
}