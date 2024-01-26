#include <stdio.h>
int main(){
int a,b,c,d;
a = 5; // 6
b = a++; // 7
c = ++b; // 6
d = b++; // 6

printf("a=%d\nb=%d\nc=%d\nd=%d\n",a,b,c,d);

int x,y,z,w;
x=10;
y=9;
z=8;
w=7;
if((x==y++) && (z==++x)){
        w = 100;
        printf("This is obviously true");
}
z = ++w+y++;
printf("x=%d\ny=%d\nz=%d\nw=%d\n",x,y,z,w);
}
