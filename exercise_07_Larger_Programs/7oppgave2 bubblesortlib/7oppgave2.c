#include <stdio.h>
#include "bubblesort.h"


int main(int argc, char**argv){
    int array[] = {2,4,1,8,4,8,4,9,4589,0};
    bubbleSort(array,10);
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", array[i]);
    }
    return 0;
}