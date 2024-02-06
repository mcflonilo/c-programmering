#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char* arr[], int i, int j){
	char temp[25];
	strcpy(temp,arr[i]);
	strcpy(arr[i],arr[j]);
	strcpy(arr[j],temp);
}
void printArray(char* arr[], int arraySize){
	int i;
	for (i = 0; i<arraySize;i++){
		printf("%s ",arr[i]);
}
}
void makeArray(char* array[], int arraysize, char** numbers){
	int i;
	for(i = 1; i<arraysize;i++){
		array[i-1]=numbers[i];
	}
}

int main(int argc, char **argv){
	//makeArray(array,argc,argv);
	int i, j;
	int arraySize = sizeof(array)/sizeof(array[0]);
	for(i = 0;i<arraySize-1;i++){
		for(j=0;j<arraySize-1;j++){
			if(strcmp(array[i],array[j])<0){
				swap(array,i,j);
			}
		}
	}
printArray(array, arraySize);
}
