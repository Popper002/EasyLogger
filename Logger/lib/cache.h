#ifndef CACHE_H
#define CACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

typedef enum
{
    FILE_OPEN,
    FILE_CLOSE,
    FILE_READ,
    FILE_WRITE,
    FILE_CREATE,
    FILE_DELETE

}FileOperation; 
typedef struct{
    char buffer[256]; 
    int isOnCache; 
    int indexOfnearWord; //indice necessario per salvare i bytes che si trovano vicino alla parola richiesta una volta 
}Cache; 
bool is_in_cache(const char *s); 
FILE* fileHandler(FILE *fp,const char* path, FileOperation fo);
int read_from_file(FILE *fp, size_t num_of_bytes_to_read);
char* read_something_from_file(const char* str, size_t num_of_bytes_to_read);  
Cache initCache(); 
#endif