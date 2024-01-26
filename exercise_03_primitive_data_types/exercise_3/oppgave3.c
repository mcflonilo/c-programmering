#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
int input = atoi(argv[1]);
if(input==0){
	printf("enter valid input!!");
}
else{
	if(input%2){
		printf("odd!");
	}
	else printf("even!");}
return 0;
}
