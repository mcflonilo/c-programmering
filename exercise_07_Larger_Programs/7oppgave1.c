//
// Created by lar on 3/4/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter(){
    static int c = 0;
    c++;
    return c;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", counter());
    }
    return 0;
}