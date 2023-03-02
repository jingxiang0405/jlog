#include "jlog.h"
#include <time.h>
#include <stdarg.h>
#define ANSI_RED    "\e[0;31m"
#define ANSI_GREEN  "\e[0;32m"
#define ANSI_YELLOW "\e[0;33m"
#define ANSI_BLUE   "\e[0;34m"
#define ANSI_URED "\e[4;31m"
#define ANSI_CYAN "\e[0;36m"
#define ANSI_HBLUE "\e[0;94m"
#define ANSI_RESET "\e[0m"
FILE *log_file;


typedef struct {
    char *str;
    char *color;
} __level__;

/*
*   The default time format is set to "MM/DD hh:mm:ss"
*
*
*/
static char __TimeBuf__[20];
static char __MessageBuf__[50];
static __level__ __levels__[7] = {
    {.str = "ALL", .color = ""},
    {.str = "TRACE", .color = ANSI_CYAN},
    {.str = "DEBUG", .color = ANSI_GREEN},
    {.str = "INFO", .color = ANSI_BLUE},
    {.str = "WARN", .color = ANSI_YELLOW},
    {.str = "ERROR", .color = ANSI_RED},
    {.str = "FATAL", .color = ANSI_URED}
};
void jlog (enum LOG_LEVEL level, const char *format, ...) {
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    strftime(__TimeBuf__, 20, "%m/%d %X", &tm);
    va_list ap;
    va_start(ap, format);
    vsprintf(__MessageBuf__, format, ap);
    if(!log_file)printf(ANSI_HBLUE"[%s]"ANSI_RESET" %s%-5s"ANSI_RESET" : %s\n", __TimeBuf__ ,__levels__[level].color, __levels__[level].str, __MessageBuf__);
    else fprintf(log_file,"[%s] %-5s : %s\n", __TimeBuf__, __levels__[level].str, __MessageBuf__);
    
}

void jlog_SetFilePath (const char *filepath) { log_file = fopen(filepath, "w"); }
