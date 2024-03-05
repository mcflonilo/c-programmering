#include "bubblesort.h"
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