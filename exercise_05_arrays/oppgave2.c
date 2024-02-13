//
// Created by lar on 2/9/24.
//
#include <stdio.h>
int main(int argc, char**argv){
    int i=0;
    while(argv[1][i]!='\0'){i++;}
    printf("%d",i);
    return 0;

}
