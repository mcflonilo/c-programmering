//
// Created by lar on 3/6/24.
//

#ifndef LOGGER_H
#define LOGGER_H
extern int glob_bTraceEnable;
#include <stdio.h>
void PgDbgLogger(unsigned long ulErrorType, int iLine, const char*szFile, const char *format ,...);
#define pgError(...) PgDbgLogger(0,__LINE__,__FILE__, __VA_ARGS__);
#define pgDebug(...) if(glob_bTraceEnable == 1)PgDbgLogger(1,__LINE__,__FILE__,__VA_ARGS__);

#endif //LOGGER_H