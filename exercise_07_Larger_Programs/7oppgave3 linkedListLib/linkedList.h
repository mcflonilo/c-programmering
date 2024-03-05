//
// Created by lar on 3/5/24.
//

#ifndef C_PROGRAMMERING_LINKEDLIST_H
#define C_PROGRAMMERING_LINKEDLIST_H

#endif //C_PROGRAMMERING_LINKEDLIST_H

typedef struct _LIST {
    int index;
    struct _LIST *pNext;
    int iSze;
    char cBuf[1];
} LIST;

void addNode(char *data, LIST *nodes);
void printNodes(LIST *nodes);
void addFirst(LIST **nodes, char *data);
void removeElement(char *data, LIST *nodes);
void freeMem(LIST *head);