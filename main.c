#include <stdio.h>
#include "c debugger project/logger.h"
#include <stdio.h>
#include <stdarg.h>
void PgDbgLogger(unsigned long ulErrorType, int iLine, const char*szFile, const char *format ,...){
    va_list args;
    static long count;
    count++;
    static FILE *fLogFile;
    const char *mode = (ulErrorType==1)?"Error":"debug";
    if(fLogFile==NULL){
        fLogFile = fopen("c debugger project/debug.txt", "rb");
        if(fLogFile==NULL){
            printf("error opening debug file");
            return;
        }
    }
    if(ulErrorType){
        printf("debug");
    }
    else{ printf("error");}

    va_start(args, format);
    vfprintf(fLogFile,format,args);
    va_end(args);
    fprintf(fLogFile, "%04li; %s %s", count, mode,"hei");
}

int main(){
    printf("hei");
    printf("hei");
    printf("hei");
    PgDbgLogger(1,__LINE__,__FILE__,"%s","c suxx");
    //pgError("hei");
    //pgDebug("hva skjer");
    printf("hei");
    return 1;
}
