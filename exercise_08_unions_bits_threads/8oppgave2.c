//
// Created by lar on 3/12/24.
//
#include <stdio.h>
void binPrint(unsigned int input){

    printf("%08b\n",input);

}

void bitFlip( char input){
    char inverted = ~input;
    printf("%b %c\n",input, input);
    printf("%b %c\n",inverted, inverted);
}

int main(){

    unsigned int binOut = 9;
    char binFlip = 'A';
    binPrint(binOut);
    bitFlip(binFlip);

    binFlip = 'a';
    bitFlip(binFlip);
}