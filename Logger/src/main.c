#include "../lib/cache.h"


int main(int argc, char const *argv[])
{
   
    FILE* fp = fileHandler(fp, argv[1],FILE_OPEN);

    Cache ca = initCache(); 

    fileHandler(fp,argv[1],FILE_CLOSE);

    int bytesToRead= atoi(argv[2]); 

    return 0;
}
