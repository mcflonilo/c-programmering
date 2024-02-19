//
// Created by lar on 2/19/24.
//
#include <stdio.h>
#include <stdlib.h>

int findInputLength(char *word, int size){
    for (int i = 0; i < size; ++i) {

    }

    return 0;
}
int main(int argc, char**argv)
{
    int baseInputMax = 100;
    char word[baseInputMax];
    int encoded[8];
    printf("enter word to encode");
    scanf("%s", word);
    char *filetext;
    int size;
    int inputLength = findInputLength(word, baseInputMax);
    FILE *file;
    file = fopen("exercise_06_IO/adventure.txt", "r");

    fseek(file,0l,SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    filetext = (char *) calloc(size, sizeof(char));

    char c = getc(file);
    for (int i = 0; c!=EOF; c=getc(file)) {
        filetext[i]=c;
        i++;
    }
    int i=0;
        for (int j = 0; j < size; ++j) {
            if(filetext[j]==word[i]){
                encoded[i]=j;

                printf("%c == %c at index == %d\n",filetext[j],word[i],j);
                i++;
                j+=10;
                if(i==inputLength){break;}
            }
            if(j>=size){printf("could not complete word :/"); return 0;}
        }

    for (int j = 0; i < inputLength; ++j) {
        printf("%c", word[j]);
        printf("%d\n", encoded[j]);
    }

    for (int j = 0; j < 8; ++j) {printf("%c",filetext[encoded[j]]);}

    return 0;
}