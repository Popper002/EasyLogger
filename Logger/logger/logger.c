#include "../lib/logger.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h> // Per gettimeofday
#include <syslog.h>

/*return a the log_level in string format */
char *get_log_level(enum log_level level)
{
    switch (level)
    {
    case DEBUG:
        return "DEBUG";
        break;

    case TRACE:
        return "TRACE";
        break;
    case APPERRO:
        return "APPERRO";
        break;
    case SYSERRO:
        return "SYSERRO";
        break;
    default:
        return "UNKWOWN";
        break;
    }
}

/*write a buffer inside a specific file passed to this function*/
int write_buffer(FILE *fp, char buffer[256], enum log_level level)
{
    char *funct_name = "write_buffer";

    if (fp == NULL)
    {
        fprintf(stderr, "%s %d FUNCT:%s, Error: NULL File pointer with errno: %d..\n", __FILE__, __LINE__, funct_name, errno);
        return errno;
    }
    int rc;

    struct timeval tv;
    gettimeofday(&tv, NULL); // Ottieni il tempo corrente con precisione fino ai microsecondi

    time_t time_now = tv.tv_sec;
    struct tm *tm_info = localtime(&time_now);

    char time_stamp[64];
    strftime(time_stamp, sizeof(time_stamp), "%Y-%m-%d %H:%M:%S", tm_info); // Formatta il tempo

    // generate the string with the full current time
    snprintf(time_stamp + strlen(time_stamp), sizeof(time_stamp) - strlen(time_stamp), ".%03ld", tv.tv_usec / 1000); // Aggiungi i millisecondi

    rc = fprintf(fp, "[%s]-------[Pid:%d]-------[%s]--------[%s] \n", get_log_level(level), getpid(), time_stamp, buffer);
    rc = write_on_system_log(buffer, "logger", level);
    if (rc < 0)
    {
        fprintf(stderr, "%s %d Error: NULL File pointer with errno: %d..\n", __FILE__, __LINE__, errno);
        return errno;
    }

    fflush(fp);
    return rc;
}

int write_on_system_log(char buffer[256], char *program_name, enum log_level level)
{
    int rc;
    if (program_name == NULL)
    {
        return EINVAL;
    }
#if defined(LINUX_) || defined(MAC_OS) 
    openlog(program_name, LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

    syslog(LOG_MAKEPRI(LOG_LOCAL1, LOG_NOTICE), "Program started by User %d", getuid());

    char temp_buffer[256*2];
    rc = snprintf(temp_buffer, sizeof(temp_buffer), "[%s][PID:%d] %s", get_log_level(level),getuid(),buffer);

    syslog(LOG_INFO, temp_buffer);

    closelog();

    return 0;
/*Windows syslog version*/
#else

#endif
}
