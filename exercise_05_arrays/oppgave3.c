//
// Created by lar on 2/9/24.
//
#include <stdio.h>
int main(int argc, char**argv){

    printf("%s\n", argv[1]);
    int i=0;
    while(argv[1][i]!='\0'){

        if(argv[1][i]=='a'||
            argv[1][i]=='e'||
            argv[1][i]=='i'||
            argv[1][i]=='o'||
            argv[1][i]=='u'){
            printf("%c",argv[1][i]);
        }


        i++;}
    printf("\n%d",i);
    return 0;
}