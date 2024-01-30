#include <stdio.h>
int main(){
int i;
for (i = 99; i>1;i--){
printf("%d bottles of beer on the wall, %d bottles of beer. take on down and pass it around, %d bottles of beer on the wall\n", i,i,i-1);
}
printf("1 bottle of beer on the wall, 1 bottle of beer. Take one down and pass it around, no more bottles of beer on the wall.");
return 0;
}
