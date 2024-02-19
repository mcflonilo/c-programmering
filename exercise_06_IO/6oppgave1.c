#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("exercise_06_IO/doubles.txt", "r");
    FILE *binfile;
    binfile = fopen("exercise_06_IO/binary.bin", "rwb");

    if (file == NULL) {
        printf("Error opening the file!\n");
        return 1;
    } else {
        printf("File opened successfully!\n");
    }

    char *eptr;
    double val;
    double frombin;
    char myString[500];

    while (fgets(myString, sizeof(myString), file) != NULL) {
        val = strtod(myString, &eptr);
        fwrite(&val, sizeof(val),1, binfile);
        fread(&frombin,sizeof(val),1,binfile);
        printf("original double %f, from bin = %f\n",val,frombin);
    }
    fclose(file);
    fclose(binfile);
    return 0;
}