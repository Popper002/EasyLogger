#include "../lib/logger.h"



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
        // if (fscanf(stdin, "%255s", buffer) != 1)
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            fprintf(stderr, "Invalid input, enter the debug level and the content to log..\n");

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
