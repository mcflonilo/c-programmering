#include <stdio.h>
int main(){
{
int x;
int size = sizeof(x);
printf("int size = %d\n", size);
}
{
float x;
int size = sizeof(x);
printf("float size = %d\n", size);
}
{
double x;
int size = sizeof(x);
printf("double size = %d\n", size);
}
{
long x;
int size = sizeof(x);
printf("long size = %d\n", size);
}
{
signed x;
int size = sizeof(x);
printf("signed size = %d\n", size);
}
{
unsigned x;
int size = sizeof(x);
printf("unsigned size = %d\n", size);
}
{
int* x;
int size = sizeof(x);
printf("int* size = %d\n", size);
}
{
float* x;
int size = sizeof(x);
printf("float* size = %d\n", size);
}
{
void* x;
int size = sizeof(x);
printf("void* size = %d\n", size);
}
{
int x[20];
int size = sizeof(x);
printf("int array[20] size = %d\n", size);
}
return 0;
}
