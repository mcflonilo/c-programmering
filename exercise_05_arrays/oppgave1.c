#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int* arr, int i, int j){
    int temp= arr[i];
    arr[i] = arr[j];
    arr[j]= temp;
}
void bubbleSort(int *array, int arraySize){
    int i, j;
    for(i = 0;i<arraySize-1;i++){
        for(j=0;j<arraySize-1;j++){
            if(array[j]>array[j+1]){
                swap( array, j, j + 1);
            }
        }
    }
}


int main(int argc, char**argv){
    int column = atoi(argv[1]);
    int row = atoi(argv[2]);
    int **array;
    int run;
    int input;
    int i;
    int x,y;

    //kode for 2d array med calloc
    srand(((unsigned)time(0)));
    array = (int**)calloc(column, sizeof (int*));
    for(i=0;i<column;i++){
        array[i]= (int*) calloc(row,sizeof(int));
    }
    int k = 1;
    for (int j = 0; j < column*row; ++j) {
        //printf("enter number to add to array");scanf("%d",&input);

        run=1;
        while(run){
            x = rand() % column;
            y = rand() % row;
            if(array[x][y]==0){
                array[x][y] = k;
                k++;
                run=0;
            }
        }
    }
    for(i=0;i<column;i++){
        for (int j = 0; j < row; ++j) {
            printf("|%d|",array[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<column;i++){
        bubbleSort(array[i], row);
    }

    printf("\n\n");

    for(i=0;i<column;i++){
        for (int j = 0; j < row; ++j) {
            printf("|%d|",array[i][j]);
        }
        printf("\n");
    }

    //kode for å frigjøre 2d array
    for (int j = 0; j < column; ++j) {
        free(array[j]);
    }
    free(array);
    return 0;
}