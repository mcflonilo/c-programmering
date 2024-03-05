//
// Created by lar on 3/4/24.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct _LIST {
    struct _LIST *pNext;
    int iSze;
    char cBuf[1];
} LIST;

void addNode(){}

int main(){
    char szStr[] = "this is a long string.";
    LIST *pThis = malloc(sizeof(LIST)+(sizeof(long)*100));
    strcpy(pThis->cBuf, szStr);

    printf("%s",pThis->cBuf);
    free(pThis);

}
