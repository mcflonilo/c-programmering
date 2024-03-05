//
// Created by lar on 3/4/24.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linkedList.h"


int main(){
    char szStr[] = "this is a long string.";
    char szStr2[] = "this is a long string2.";
    LIST *pThis = malloc(sizeof(LIST)+ strlen(szStr));
    strcpy(pThis->cBuf, szStr);

    addNode(szStr2, pThis);
    addFirst(&pThis,"nummer 3");
    printNodes(pThis);
    removeElement(szStr,pThis);

    printf("ææææææ\n\n\n\n");
    printNodes(pThis);

    freeMem(pThis);
}
