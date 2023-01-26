#ifndef JLOG_H
#define JLOG_H

#include <stdio.h>

enum LOG_LEVEL{
    ALL,
    TRACE, 
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL
};

extern FILE* log_file;

void jlog_SetFilePath(const char *filepath);
void jlog(enum LOG_LEVEL level, const char* message);
#endif
