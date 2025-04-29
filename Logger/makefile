CC=gcc
CFLAGS= -g
FILE=file
logger:
	$(CC) $(CFLAGS) logger/logger.c -o bin/logger
cache:
	$(CC) $(CFLAGS) src/cache.c src/main.c -o bin/cache
run:cache
	./bin/cache $(FILE)/file.txt