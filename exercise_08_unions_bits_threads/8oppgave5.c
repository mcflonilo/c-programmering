//
// Created by lar on 3/12/24.
//
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>

int globalIkkeSkytMegBengt = 0;
void *printMessage(void *pvData){
    char *pszMessage = (char *)pvData;
    printf("In %s.\n",pszMessage);
    return NULL;
}
bool isPrime(long num)
{
    int i, temp = 0;
    for (i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            temp++;
            break;
        }
    }
    if (temp == 0 && num != 1)return true;
    else return false;
}

void *threadWait(){
    int count= 0;
    while(globalIkkeSkytMegBengt==0){
        count++;
    }
    printf("threadwait number == %d\n", count);
    return NULL;
}

void *threadTest(){
    int count = 0;
    long *array;
    array = malloc(sizeof(long)*100);
    for (long i = 0; i < 1000; ++i) {
        if(isPrime(i)){
            array[count] = i;
            count++;
        }
    }
    for (int i = 0; i < count; ++i) {
        printf("%ld\n",array[i]);
    }
    printf("number of primes found%d\n", count);
    free(array);
    globalIkkeSkytMegBengt = 1;
    return NULL;
}

int main(int argc, char**argv){
    pthread_t pthread2, pthread3;
    char * message2 = "thread 2";
    printf("starting threadfs now!\n");

    pthread_create(&pthread2, NULL,threadWait, (void *) message2);
    pthread_create(&pthread3, NULL,threadTest, (void *) message2);

    printf("after threads start\n");

    pthread_join(pthread2,NULL);
    pthread_join(pthread3,NULL);

    printf("thread doneeee");
    return 0;
}


