#include <stdio.h>
int  main(){
int a,b;
int *pa = &a;
int *pb = &b;
printf("type two integersseperated with space");
scanf("%d %d", pa,pb);

if(a<b){
printf("%d b is bigger",b);
}
else {
printf("%d a is bigger",a);
}
return 0;

}
