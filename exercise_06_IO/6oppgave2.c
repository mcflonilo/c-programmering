#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int comp(int index, char *array, int size){
    int min = 2,max = 4;

    if(index+min>size){return 0;}
    int ceiling = index+max;
    if(ceiling>size){ceiling = size;}

    for (int i = index; i < ceiling; ++i) {
        for (int j = i+min; j <ceiling ; ++j) {
            if(array[i]==array[j]){
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char**argv){
    char *filetext;
    int size;
    FILE *file;
    file = fopen("exercise_06_IO/test.txt", "r");

    int doublevowelcount=0;
    int doublelettercount=0;
    int letterpairseperatedcount=0;

    int min = 2,max = 4;

    fseek(file,0l,SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    filetext = (char *) calloc(size, sizeof(char));

    char c = getc(file);
    for (int i = 0; c!=EOF; c=getc(file)) {
        filetext[i]=c;
        i++;
    }
    printf("%s\n\n", filetext);

    for (int i = 0; i < size; ++i) {
        //strcasecmp returnerer 0 hvis de er like
        if (filetext[i] == filetext[i+1]) {
            if (filetext[i] == 'a' || filetext[i] == 'e' || filetext[i] == 'i' || filetext[i] == 'o' || filetext[i] == 'u') {
                doublevowelcount++;
            } else {
                doublelettercount++;
            }
        }
        if(comp(i,filetext,size)){
            letterpairseperatedcount++;
        }
    }

    printf("doublevowels == %d\n"
           "double letters = %d\n"
           "letter pairs with seperation = %d",
           doublevowelcount,doublelettercount,letterpairseperatedcount);

    return 0;
}
