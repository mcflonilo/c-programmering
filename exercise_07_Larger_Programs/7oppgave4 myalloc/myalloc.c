//
// Created by lar on 3/6/24.
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

    if(type[0]=='c'){
        char *pChar;

        int arraySize = va_arg(args,int);
        pChar = malloc(sizeof(char) * arraySize);
        if(type[i-1] == 'T'){
            char initializationValue = va_arg(args,int); // er dette dårlig??
            for (int j = 0; j < arraySize; j++) {
                pChar[j] = initializationValue;
            }
            return pChar;
        }
        else if(type[i-1] == 'F'){
            return pChar;
        }
        else {
            printf("incorrect format returning");
            return 0;
        }
    }
    else if(type[0]=='i'){
        int *pInt;

        int arraySize = va_arg(args,int);
        pInt = malloc(sizeof(int)*arraySize);
        if(type[i-1] == 'T'){
            int initializationValue = va_arg(args,int);
            for (int j = 0; j < arraySize; j++) {
                pInt[j] = initializationValue;
            }
            return pInt;
        }
        else if(type[i-1] == 'F'){
            return pInt;
        }
        else {
            printf("incorrect format returning");
            return 0;
        }
    }
    else if(type[0]=='f'){
        double *pDouble;

        int arraySize = va_arg(args,int);
        pDouble = malloc(sizeof(double)*arraySize);
        if(pDouble==NULL){
            printf("error assigning mem");
            return 0;
        }

        if(type[i-1] == 'T'){
            double initializationValue = va_arg(args,double);
            for (int j = 0; j < arraySize; j++) {
                pDouble[j] = initializationValue;
            }
            return pDouble;
        }
        else if(type[i-1] == 'F'){
            return pDouble;
        }
        else {
            printf("incorrect format returning");
            return 0;
        }
    }
    else{ printf("unaccepted type returning"); return 0;}
}