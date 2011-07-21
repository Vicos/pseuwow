#include <stdarg.h>
#include "common.h"
#include "log.h"

#if PLATFORM == PLATFORM_WIN32
#include <windows.h>
#endif

FILE *logfile = NULL;
uint8 loglevel = 0;
bool logtime = false;

void _log(uint8 lvl, Color color, bool to_stdout, const char *msg);
void _log_setcolor(bool,Color);
void _log_resetcolor(bool);

void log_prepare(const char *fn, const char *mode = NULL)
{
    if(!mode)
        mode = "a";
    if(logfile)
        fclose(logfile);
    logfile = fopen(fn,mode);
}

void log_setloglevel(uint8 lvl)
{
    loglevel = lvl;
}

void log_setlogtime(bool b)
{
    logtime = b;
}

void log(const char *format, ...)
{
    char msg[1024];
    va_list argptr;
    
    va_start(argptr, format);
    vsprintf(msg, format, argptr);
    va_end(argptr);

    _log(loglevel,GREY,true,msg);
}

void logdetail(const char *format, ...)
{
    char msg[1024];
    va_list argptr;
    
    va_start(argptr, format);
    vsprintf(msg, format, argptr);
    va_end(argptr);

    _log(1,LCYAN,true,msg);
}

void logdebug(const char *format, ...)
{
    char msg[1024];
    va_list argptr;
    
    va_start(argptr, format);
    vsprintf(msg, format, argptr);
    va_end(argptr);

    _log(2,LBLUE,true,msg);
}

void logdev(const char *format, ...)
{
    char msg[1024];
    va_list argptr;
    
    va_start(argptr, format);
    vsprintf(msg, format, argptr);
    va_end(argptr);

    _log(3,LMAGENTA,true,msg);
}

void logerror(const char *format, ...)
{
    char msg[1024];
    va_list argptr;
    
    va_start(argptr, format);
    vsprintf(msg, format, argptr);
    va_end(argptr);

    _log(loglevel,LRED,false,msg);
}

void logcritical(const char *format, ...)
{
    char msg[1024];
    va_list argptr;
    
    va_start(argptr, format);
    vsprintf(msg, format, argptr);
    va_end(argptr);

    _log(loglevel,RED,false,msg);
}

void logcustom(uint8 lvl, Color color, const char *format, ...)
{
    char msg[1024];
    va_list argptr;
    
    va_start(argptr, format);
    vsprintf(msg, format, argptr);
    va_end(argptr);

    _log(loglevel,color,true,msg);
}

void log_close()
{
	fclose(logfile);
}

void _log(uint8 lvl, Color color, bool to_stdout, const char *msg)
{
    if(!msg || loglevel < lvl)
        return;
    _log_setcolor(to_stdout,color);
    if(logtime)
        printf("%s ", GetTimeString().c_str());
    printf("%s\n",msg);
    _log_resetcolor(true);
    fflush(stdout);
    
    if(logfile)
    {
        fprintf(logfile, "%s", getDateString().c_str());
        fprintf(logfile, "%s\n", msg);
        fflush(logfile);
    }
}

void _log_setcolor(bool stdout_stream, Color color)
{
#if PLATFORM == PLATFORM_WIN32

    static WORD WinColorFG[Color_count] =
    {
        0,                                                  // BLACK
            FOREGROUND_RED,                                     // RED
            FOREGROUND_GREEN,                                   // GREEN
            FOREGROUND_RED | FOREGROUND_GREEN,                  // BROWN
            FOREGROUND_BLUE,                                    // BLUE
            FOREGROUND_RED |                    FOREGROUND_BLUE,// MAGENTA
            FOREGROUND_GREEN | FOREGROUND_BLUE,                 // CYAN
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,// WHITE
            // YELLOW
            FOREGROUND_RED | FOREGROUND_GREEN |                   FOREGROUND_INTENSITY,
            // RED_BOLD
            FOREGROUND_RED |                                      FOREGROUND_INTENSITY,
            // GREEN_BOLD
            FOREGROUND_GREEN |                   FOREGROUND_INTENSITY,
            FOREGROUND_BLUE | FOREGROUND_INTENSITY,             // BLUE_BOLD
            // MAGENTA_BOLD
            FOREGROUND_RED |                    FOREGROUND_BLUE | FOREGROUND_INTENSITY,
            // CYAN_BOLD
            FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
            // WHITE_BOLD
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
    };

    HANDLE hConsole = GetStdHandle(stdout_stream ? STD_OUTPUT_HANDLE : STD_ERROR_HANDLE );
    SetConsoleTextAttribute(hConsole, WinColorFG[color]);
#else

    enum ANSITextAttr
    {
        TA_NORMAL=0,
        TA_BOLD=1,
        TA_BLINK=5,
        TA_REVERSE=7
    };

    enum ANSIFgTextAttr
    {
        FG_BLACK=30, FG_RED,  FG_GREEN, FG_BROWN, FG_BLUE,
        FG_MAGENTA,  FG_CYAN, FG_WHITE, FG_YELLOW
    };

    enum ANSIBgTextAttr
    {
        BG_BLACK=40, BG_RED,  BG_GREEN, BG_BROWN, BG_BLUE,
        BG_MAGENTA,  BG_CYAN, BG_WHITE
    };

    static uint8 UnixColorFG[Color_count] =
    {
        FG_BLACK,                                           // BLACK
            FG_RED,                                             // RED
            FG_GREEN,                                           // GREEN
            FG_BROWN,                                           // BROWN
            FG_BLUE,                                            // BLUE
            FG_MAGENTA,                                         // MAGENTA
            FG_CYAN,                                            // CYAN
            FG_WHITE,                                           // WHITE
            FG_YELLOW,                                          // YELLOW
            FG_RED,                                             // LRED
            FG_GREEN,                                           // LGREEN
            FG_BLUE,                                            // LBLUE
            FG_MAGENTA,                                         // LMAGENTA
            FG_CYAN,                                            // LCYAN
            FG_WHITE                                            // LWHITE
    };

    fprintf((stdout_stream? stdout : stderr), "\x1b[%d%sm",UnixColorFG[color],(color>=YELLOW&&color<Color_count ?";1":""));
#endif
}

void _log_resetcolor(bool stdout_stream)
{
#if PLATFORM == PLATFORM_WIN32
    HANDLE hConsole = GetStdHandle(stdout_stream ? STD_OUTPUT_HANDLE : STD_ERROR_HANDLE );
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
#else
    fprintf(( stdout_stream ? stdout : stderr ), "\x1b[0m");
#endif
}
