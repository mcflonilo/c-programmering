//
// Created by lar on 3/6/24.
//

#ifndef C_PROGRAMMERING_LOGGER_H
#define C_PROGRAMMERING_LOGGER_H
void PgDbgLogger(unsigned long ulErrorType, int iLine, const char*szFile, const char *format ,...);
#define pgError(...) PgDbgLogger(0,__LINE__,__FILE__, __VA_ARGS__);
#define pgDebug(...) if(glob_bTraceEnable == 1)PgDbgLogger(1,__LINE__,__FILE__,__VA_ARGS__);

#endif //C_PROGRAMMERING_LOGGER_H