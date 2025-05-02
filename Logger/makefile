CC = gcc
CFLAGS = -g -D LINUX_ -D MAC_OS
DEST_LIB = lib
DEST_BIN = bin
RM_ALL_FILE = rm

# Target principale per creare tutto
all: liblogger.a main

# Creazione della libreria statica
liblogger.a: logger/logger.o
	ar rcs $(DEST_LIB)/liblogger.a logger/logger.o

# Compilazione del file oggetto per la libreria
logger/logger.o: logger/logger.c
	$(CC) $(CFLAGS) -c logger/logger.c -o logger/logger.o

# Compilazione del programma principale che utilizza la libreria
main: src/main.c liblogger.a
	$(CC) $(CFLAGS) src/main.c -o $(DEST_BIN)/main $(DEST_LIB)/liblogger.a

# Pulizia dei file generati
clean:
	$(RM_ALL_FILE) $(DEST_LIB)/* $(DEST_BIN)/* logger/*.o