CC = gcc
CFLAGS = `pkg-config --cflags --libs glib-2.0`

EXECUTABLE = main
SOURCES = main.c util.c crypto-algorithms/sha256.c
HEADERS = main.h crypto-algorithms/sha256.h

all:
	$(CC) -o $(EXECUTABLE) $(SOURCES) $(HEADERS) $(CFLAGS)

clean:
	rm -f $(EXECUTABLE)
