//
// Created by lar on 3/5/24.
//
#include "linkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



void addNode(char *data, LIST *currentNode){
    //initialize node
    LIST *newNode = malloc(sizeof(LIST)+strlen(data));
    strcpy(newNode->cBuf, data);
    //go tolast node in list and set its nodepouinter to this one
    while(currentNode->pNext != NULL){
        currentNode = currentNode->pNext;
    }
    currentNode->pNext = newNode;
}

void printNodes(LIST *nodes){
    //go through list and print
    while(nodes->pNext != NULL){
        printf("%s\n",nodes->cBuf);
        nodes=nodes->pNext;
    }
    //print last node
    printf("%s\n",nodes->cBuf);
}

void addFirst(LIST **nodes, char *data){
    LIST *newNode = malloc(sizeof(LIST)+strlen(data));
    strcpy(newNode->cBuf, data);

    newNode->pNext = *nodes;

    *nodes = newNode;
}

void removeElement(char *data, LIST *nodes){
    printf("fjerner element");
    LIST *prevNode;
    int isFirst =0;
    if (nodes==NULL){return;}
    while(strcmp(nodes->cBuf,data) != 0 && nodes->pNext!=NULL){


        isFirst++;
        prevNode = nodes;
        nodes= nodes->pNext;
    }
    if(strcmp(nodes->cBuf,data)==0){
        //hvis det er siste element
        if (nodes->pNext==NULL){
            prevNode->pNext=NULL;
            //free(nodes->cBuf);
            free(nodes);
        }
            //hvis det er første element
        else if (isFirst==0){
            //free(nodes->cBuf);
            free(nodes);
        }
            //hvis det er hvilket som helst annet
        else{
            prevNode->pNext=nodes->pNext;
            //free(nodes->cBuf);
            free(nodes);
        }
    }
    else{
        printf("fant ikke element");
    }
}

void freeMem(LIST *head){
    LIST *prevNode;
    while (head->pNext!=NULL){
        prevNode = head;
        free(head);
        head = prevNode->pNext;
    }
    free(head);
}