#include <stdio.h>
#include <stdlib.h>
void swap(int* arr, int i, int j){
	int temp= arr[i];
	arr[i] = arr[j];
	arr[j]= temp;
}
void printArray(int arr[], int arraySize){
	int i;
	for (i = 0; i<arraySize;i++){
		printf("%d ",arr[i]);
}
}
void makeArray(int* array, int arraysize, char** numbers){
	int i;
	for(i = 0; i<arraysize;i++){
		array[i]=atoi(numbers[i]);
	}
}

int main(int argc, char **argv){
	int array[argc];
	makeArray(array,argc,argv);
	int i, j;
	int arraySize = sizeof(array)/sizeof(array[0]);
	for(i = 0;i<arraySize-1;i++){
		for(j=0;j<arraySize-1;j++){
			if(array[j]>array[j+1]){
				swap(array,j,j+1);
			}
		}
	}
printArray(array, arraySize);
}
