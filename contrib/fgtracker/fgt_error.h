/*
 * error.h - headers for error handlling functions
 *
 *   Author: Gabor Toth <tgbp@freemail.hu>
 *   License: GPL
 *
 *   $Log: error.h,v $
 *   Revision 1.2  2006/05/10 21:22:34  koversrac
 *   Comment with author and license has been added.
 *
 */

#include    "fgt_common.h"
#include    <stdarg.h>          /* ANSI C header file */ 
#ifndef _MSC_VER
#include    <syslog.h>          /* for syslog() */ 
#endif // !_MSC_VER

extern int     daemon_proc;            /* set nonzero by daemon_init() */ 

/* Nonfatal error related to system call 
 * Print message and return */ 

extern void err_ret(const char *fmt, ...) ;


/* Fatal error related to system call 
 * Print message and terminate */ 

extern void err_sys(const char *fmt, ...) ;


/* Fatal error related to system call 
 * Print message, dump core, and terminate */ 

extern void err_dump(const char *fmt, ...) ;


/* Nonfatal error unrelated to system call 
 * Print message and return */ 

extern void err_msg(const char *fmt, ...) ;


/* Fatal error unrelated to system call 
 * Print message and terminate */ 

extern void err_quit(const char *fmt, ...) ;


/* Print message and return to caller 
 * Caller specifies "errnoflag" and "level" */ 

extern void err_doit(int errnoflag, int level, const char *fmt, va_list ap) ;


extern void debug(int level,char *str);

