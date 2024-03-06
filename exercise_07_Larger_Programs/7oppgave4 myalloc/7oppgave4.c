//
// Created by lar on 3/5/24.
//
#include <stdio.h>
#include <stdarg.h>
#include "myalloc.h"
#include <string.h>
#include <stdlib.h>

void *myalloc(const char *type, ...){
    va_list args;
    va_start(args,type);
    int i = strlen(type);

    printf("%c\n",type[0]);
    if(type[0]=='c'){
        if(type[i] == 'T'){

        }

    }
    else if(type[0]=='i'){

        int *pInt;

        int arraySize = va_arg(args,int);
        printf("%d\n",arraySize);
        pInt = malloc(sizeof(int)*arraySize);
        if(type[i-1] == 'T'){
            int initializationValue = va_arg(args,int);
            printf("initval==%d",initializationValue);
            for (int j = 0; j < arraySize; ++j) {
                pInt[i] = initializationValue;
            }
        }
    }
    else if(type[0]=='f'){
        if(type[i] == 'T'){

        }
    }
    else{ printf("unaccepted type returning"); return 0;}
}

void simple_printf(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    while (*fmt != '\0') {
        if (*fmt == 'd') {
            int i = va_arg(args, int);
            printf("%d\n", i);
        } else if (*fmt == 'c') {
            // note automatic conversion to integral type
            int c = va_arg(args, int);
            printf("%c\n", c);
        } else if (*fmt == 'f') {
            double d = va_arg(args, double);
            printf("%f\n", d);
        }
        ++fmt;
    }

    va_end(args);
}

int main(void)
{
    int *p;
    printf("heo");
    p = (int *)myalloc("int T",100,4);
    //printf("%d",p[0]);
    //free(p);
}