//
// Created by lar on 3/11/24.
//
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
int glob_bTraceEnable =0;
#include "logger.h"
void PgDbgLogger(unsigned long ulErrorType, int iLine, const char*szFile, const char *format ,...){
    va_list args;
    static long count;
    count++;
    static FILE *fLogFile;
    const char *mode = (ulErrorType==1)?"error":"debug";
    if(mode){
        glob_bTraceEnable=1;
    }

    //making file
    if(fLogFile==NULL){
        time_t t = time(NULL);
        char filename[256];
        snprintf(filename, 256-1,"debug/debug_%li.txt",t);
        fLogFile = fopen(filename, "w+");
    }

    va_start(args, format);
    vfprintf(fLogFile,format,args);
    va_end(args);
    fprintf(fLogFile, " at line %04li from file %s\n", iLine, szFile);
}