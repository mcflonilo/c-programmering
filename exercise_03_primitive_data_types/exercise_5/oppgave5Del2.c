#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
srand(time(NULL));
   int a = rand()%40;
   int sum = 0;
   for(;a>0;a--){
   sum = sum +a--;
   }
   printf("sum is %d", sum);
}
