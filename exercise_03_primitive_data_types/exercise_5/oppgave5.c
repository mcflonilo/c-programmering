#include <time.h>
#include <stdlib.h>
#include <stdio.h>
int main(){
	srand(time(NULL));
	int a = rand()%20;
	switch(a){
		case 1:
			printf("%d is prime", a);
			break;
		case 2:
			printf("%d is prime", a);
			break;
		case 3:
			printf("%d is prime", a);
			break;
		case 5:
			printf("%d is prime", a);
			break;
		case 7:
			printf("%d is prime", a);
			break;
		case 11:
			printf("%d is prime", a);
			break;
		case 13:
			printf("%d is prime", a);
			break;
		case 17:
			printf("%d is prime", a);
			break;
		case 19:
			printf("%d is prime", a);
			break;
		default:
			printf("%d is not prime", a);
			break;
		}
	return 0;
}

