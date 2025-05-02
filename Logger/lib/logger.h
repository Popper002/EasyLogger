#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h> 
#include <unistd.h>
#include <string.h>
enum log_level{
    DEBUG,
    TRACE,
    APPERRO,
    SYSERRO
};
/*return a the log_level in string format */
char* get_log_level(enum log_level level); 

/*write a buffer inside a specific file passed to this function*/
int write_buffer(FILE *fp, char buffer[256], enum log_level level); 

/**/
int write_on_system_log(char buffer[256], char *program_name, enum log_level level);



#endif