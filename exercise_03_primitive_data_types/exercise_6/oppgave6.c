#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
unsigned long GetTime(){
struct timeval tv;
gettimeofday(&tv,NULL);
return tv.tv_sec*(unsigned long)1000000+tv.tv_usec;
}


int main(int argc, char **argv){

unsigned long timeStart, timeEnd;
        timeStart = GetTime();


int input = atoi(argv[1]);
long fib[input];
fib[0] = 0;
fib[1] = 1;
for(int i = 2;i<=input;i++){
	fib[i] = fib[i-1]+fib[i-2];
	printf("%ld\n",fib[i]);
}
timeEnd = GetTime();
        printf("The elapsed time is %lu ms", (timeEnd - timeStart));

return 0;
}
