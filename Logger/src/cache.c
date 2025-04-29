#include "../lib/cache.h"
Cache initCache()
{
    Cache ca; 
    ca.indexOfnearWord=0; 
    ca.isOnCache=0;
    return ca; 
}
FILE* fileHandler(FILE *fp, const char* path,FileOperation fo){
    if(fp==NULL)
    {
        return NULL; 
    }
    switch (fo)
    {
    case FILE_OPEN:
        fp = fopen(path,"r");
        if(fp ==NULL)
        {
            return NULL;  
        }
        printf("FILE %s APERTO\n",path); 
        return fp; 
        break;
    case FILE_CLOSE:
        fclose(fp);
        printf("FILE %s CHIUSO\n",path); 

    default:
        break;
    }
    return fp; 
}