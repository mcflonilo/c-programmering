//
// Created by lar on 3/8/24.
//
#include <stdio.h>
#include <stdlib.h>

struct __attribute__((packed)) tga{
    char  identificationField;
    char  colourmaptype;
    char  datatypecode;
    //color map specification
    short int colourmaporigin; //index of first color map entry
    short int colourmaplength;// count of color map entries
    char  colourmapentrySize;// numer of bits in color map entry
    //image specs
    short int x_origin; //x coord of lower left corner
    short int y_origin;// y coord of lower left corner
    short width;// width of image in pixels
    short height;//height of image in pixels
    char  bitsperpixel;
    char  imagedescriptor;
};

int main(){
    struct tga header;
    FILE *file;
    file = fopen("exercise_08_unions_bits_threads/sample_640×426.tga","rb"); // r for å lese, b for å spesifisere i binær modus
    fread(&header, sizeof(struct tga), 1, file);


    printf("id idlength %d\n", header.identificationField);
    printf("id colourmaptype %d\n", header.colourmaptype);
    printf("id datatypecode %d\n", header.datatypecode);
    printf("id colourmaporigin %d\n", header.colourmaporigin);
    printf("id colourmaplength %d\n", header.colourmaplength);
    printf("id colourmapdepth %d\n", header.colourmapentrySize);
    printf("id x %d\n", header.x_origin);
    printf("id y %d\n", header.y_origin);
    printf("id width %d\n", header.width);
    printf("id height %d\n", header.height);
    printf("id bitperpixel %c\n", header.bitsperpixel);
    printf("id imagedescriptor %c\n", header.imagedescriptor);
}