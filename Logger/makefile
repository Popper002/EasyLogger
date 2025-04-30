CC=gcc
CFLAGS= -g -D LINUX_ -D MAC_OS
FILE=file
logger:
	$(CC) $(CFLAGS) logger/logger.c -o bin/logger
logger_unix:
	$(CC) $(CFLAGS) -D LINUX_ logger/logger.c -o bin/logger
cache:
	$(CC) $(CFLAGS) src/cache.c src/main.c -o bin/cache
run:cache
	./bin/cache $(FILE)/file.txt