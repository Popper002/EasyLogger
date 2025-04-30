#include "../lib/cache.h"
#include "../lib/logger.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h> // Per gettimeofday

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
    snprintf(time_stamp + strlen(time_stamp), sizeof(time_stamp) - strlen(time_stamp), ".%03ld", tv.tv_usec / 1000); // Aggiungi i millisecondi

    rc = fprintf(fp, "[%s]-->[Pid:%d]-->[%s]-->[%s] \n", get_log_level(level), getpid(), time_stamp, buffer);
    if (rc < 0)
    {
        fprintf(stderr, "%s %d Error: NULL File pointer with errno: %d..\n", __FILE__, __LINE__, errno);
        return errno;
    }

    fflush(fp);
    return rc;
}

int main(int argc, char const *argv[])
{

    /*Check the correct number of arguments passed */
    if (argc < 2)
    {
        fprintf(stderr, "invalid argument num..\n");
        return -1;
    }

    /*open the file*/
    FILE *fp = fopen(argv[1], "a");

    /*check the result of fopen*/
    if (fp == NULL)
    {
        fprintf(stderr, "invalid fp ..\n");
        return -1;
    }
    /*create a buffer*/
    char buffer[256];
    int debug_value = 0;
    while (1)
    {
        printf(">");

        /*while reading */
        //if (fscanf(stdin, "%255s", buffer) != 1)
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) 
        {
            fprintf(stderr, "Invalid input, enter the debug level and the content to log..\n");
            // Svuota il buffer di input
            // int c;
            /*
            *
            * Cos'è il buffer di input (stdin)?
Quando inserisci dati tramite tastiera, questi vengono memorizzati in un buffer di input (una sorta di "coda" di caratteri) prima di essere elaborati dal programma. Funzioni come fscanf, scanf, o getchar leggono i dati da questo buffer.

Problema: Caratteri non consumati
Se una funzione come fscanf non riesce a leggere correttamente i dati (ad esempio, a causa di un input non valido), i caratteri rimanenti nel buffer non vengono automaticamente rimossi. Questo può causare problemi, come:

Loop infinito: Se il buffer contiene ancora dati non validi, il programma tenterà di leggerli di nuovo al prossimo ciclo, fallendo continuamente.
Comportamento imprevedibile: I caratteri rimanenti possono interferire con le successive letture.
Esempio del problema:
Supponiamo che il programma stia aspettando un input del tipo int string (ad esempio, 1 hello), ma l'utente inserisce solo hello:
            *
            *
            * * * * */
            // while ((c = getchar()) != '\n' && c != EOF);
            fflush(stdin);
            strcpy(buffer, "INVALID INPUT");

            write_buffer(fp, buffer, APPERRO);

            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, ".exit") == 0)
        {
            printf("\tEXITING..\n");

            // you can use snprintf
            strcpy(buffer, "EXITING");

            write_buffer(fp, buffer, TRACE);

            break;
        }

        write_buffer(fp, buffer, atoi(argv[2]));
    }
    /* close the file is important */
    fclose(fp);

    return 0;
}
